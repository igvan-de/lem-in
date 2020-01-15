/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/15 18:47:26 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This functions adds a new room to the existing queue*/
static void	add_to_queue(t_queue **queue, t_queue *new)
{
	t_queue	*probe;

	if (new == NULL)
		return ;
	if ((*queue) == NULL)
	{
		(*queue) = new;
		return ;
	}
	probe = *queue;
	while (probe->next != NULL)
		probe = probe->next;
	probe->next = new;
}

/*this function checks if the node is pointing to end when node is end*/
static int	check_end(t_rooms *current_room, t_rooms *connected_room)
{
	if (connected_room->towards == NULL)
		return (FALSE);
	if (current_room->type == END && connected_room->towards->type == END)
		return (TRUE);
	return (FALSE);
}

/*this function return the node of the connected room which is also part of exiting path,
to follow the path aat least one time. It also check if connected room arent part of a path
and adds them to queue with right diastance value and branch pointer to room*/
static void	follow_path(t_queue **queue, t_rooms *room, t_links *connected_rooms)
{
	t_links	*connected;
	t_links	*path_connected;

	connected = connected_rooms;
	path_connected = NULL; /*not sure if this is needed!*/
	while (connected != NULL)
	{
		if (connected->room->visited == FALSE)
		{
			if (connected->room->path_id == room->path_id && room->towards == connected->room)
			{
				room = connected->room;
				room->visited = TRUE;
				room->distance = -2;
				path_connected = connected->room->links;
			}
			if (connected->room->path_id != room->path_id)
			{
				connected->room->visited = TRUE;
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
		if (connected->room->path_id == room->path_id && room->towards == connected->room)
		{
			connected->room->visited = TRUE;
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
	if (current_room->path_id == FALSE)
	{
		while (connected != NULL)
		{
			if (connected->room->visited == FALSE && check_end(current_room, connected->room) == FALSE)
			{
				connected->room->visited = TRUE;
				connected->room->distance = current_room->distance + 1;
				add_to_queue(queue, new_element(connected->room));
			}
			connected = connected->next;
		}
	}
	else if (current_room->path_id != FALSE)
		on_path(queue, current_room);
}

/*This functions pops the first room of the queue*/
void	pop_out_queue(t_queue **queue)
{
	t_queue	*first_node;

	first_node = *queue;
	(*queue) = (*queue)->next;
	first_node = NULL;
	free(first_node);
}
