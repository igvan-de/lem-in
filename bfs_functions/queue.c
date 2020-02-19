/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/19 16:11:32 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Checks if the node is pointing to end when node is end
*/

static bool	connected_to_end(t_rooms *current_room, t_rooms *connected_room)
{
	if (connected_room->towards == NULL)
		return (false);
	if (current_room->type == END && connected_room->towards->type == END)
		return (true);
	return (false);
}

/*
** Checks if start and end rooms are linked with eachother
** returns true if they are and end room doenst have a path_id
*/

static bool	start_end_connection(t_rooms *current_room, t_rooms *connected_room)
{
	if (current_room->type == END && connected_room->type == START
	&& current_room->path_id != false)
		return (true);
	return (false);
}

/*
** Returns the connected room which is also part of an exiting path
** Also checks if connected rooms aren't part of a path and adds
** them to the queue with the right distance value and branch pointer
*/

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
				connected->room->branch = (*queue)->room;
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

/*
** Follows path in the right direction
*/

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

/*
** Creates the queue by adding the linked rooms of current room to queue,
** if linked room inst visited or when linked room is visited it will go to on_path function
*/

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
