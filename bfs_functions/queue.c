/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/24 16:14:01 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*this function checks if the node is pointing to end when node is end*/
static bool	connected_to_end(t_rooms *current_room, t_rooms *connected_room)
{
	if (connected_room->towards == NULL)
		return (false);
	if (current_room->type == END && connected_room->towards->type == END)
		return (true);
	return (false);
}

static bool	start_end_connection(t_rooms *current_room, t_rooms *connected_room)
{
	if (current_room->type == END && connected_room->type == START
	&& current_room->path_id != false)
		return (true);
	return (false);
}

/*this function return the node of the connected room which is also part of exiting path,
to follow the path aat least one time. It also check if connected room arrent part of a path
and adds them to queue with right distance value and branch pointer to room*/
static void	follow_path(t_queue **queue, t_rooms *room, t_links *connected_rooms)
{
	t_links	*connected;
	t_links	*path_connected;

	connected = connected_rooms;
	path_connected = NULL;
	while (connected != NULL)
	{
		if (connected->room->visited == false)
		{
			if (connected->room->path_id == room->path_id && room->towards == connected->room)
			{
				room = connected->room;
				room->visited = true;
				room->distance = -2;
				path_connected = connected->room->links;
			}
			if (connected->room->path_id != room->path_id)
			{
				connected->room->visited = true;
				connected->room->branch = (*queue)->room;
				connected->room->distance = (*queue)->room->distance + 1;
				add_to_queue(queue, new_element(connected->room));
			}
		}
		if (connected->next == NULL && path_connected != NULL)
			return (follow_path(queue, room, path_connected));
		connected = connected->next;
	}
}

/*this function stays on path an go in the right direction*/
static void	on_path(t_queue **queue, t_rooms *room)
{
	t_links	*connected;

	connected = room->links;
	while (connected != NULL)
	{
		if (connected->room->path_id == room->path_id &&
		room->towards == connected->room && connected->room->type != END)
		{
			connected->room->visited = true;
			connected->room->branch = room;
			follow_path(queue, connected->room, connected->room->links);
		}
		connected = connected->next;
	}
}

/*This functions create the queue by adding the connecting rooms of current room to queue,
this only happens if the connected rooms meet the rules we made before we want to add them*/
void		create_queue(t_queue **queue)
{
	t_links	*connected;
	t_rooms	*current_room;

	if ((*queue)->room->type == START)
		return ;
	current_room = (*queue)->room;
	connected = current_room->links;
	if (current_room->path_id == false || current_room->type == END)
	{
		while (connected != NULL)
		{
			if (connected->room->visited == false && connected_to_end(current_room, connected->room) == false
			&& start_end_connection(current_room, connected->room)== false)
			{
				connected->room->visited = true;
				connected->room->distance = current_room->distance + 1;
				add_to_queue(queue, new_element(connected->room));
			}
			connected = connected->next;
		}
	}
	else if (current_room->path_id != false)
		on_path(queue, current_room);
}
