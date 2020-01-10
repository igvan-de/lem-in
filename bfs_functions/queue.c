/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/10 17:36:48 by igvan-de      ########   odam.nl         */
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

/*This function follows the path of connecting rooms*/
static void	follow_path(t_queue **queue, t_rooms *room)
{
	t_links *connected;

	connected = room->links;
	while (connected != NULL)
	{
		/*follow direction of path by checking the path_id's
		and if the connected room is the same room as room->towards is pointing to*/
		if (connected->room->visited == FALSE) /*check if this statement is needed again*/
		{
			if (connected->room->path_id == room->path_id && connected->room == room->towards)
			{
				/* NEED TO CHECK THIS LATER!
				don't increase the first time the distance,
				all the other times following a path its needed*/
				room->visited = TRUE;
				connected->room->visited = TRUE;
				/*need to make statement that if it's the second room on path
				distance will be incremented*/
				room->distance = CURRENT_QUEUE_ROOM_DISTANCE + 1;
				connected->room->distance = room->distance;
				add_to_queue(queue, new_element(room));
				add_to_queue(queue, new_element(connected->room));
			}
			/*go to new room which is part of an other path
			don't go to room->type START*/
			else if (connected->room->path_id != room->path_id && connected->room->type != START)
			{
				connected->room->visited = TRUE;
				connected->room->distance = CURRENT_QUEUE_ROOM_DISTANCE + 1;
				add_to_queue(queue, new_element(connected->room));
			}
		}
		connected = connected->next;
	}
}

/*This functions create the queue by adding the connecting rooms of current room to queue,
this only happens if the connected rooms meet the rules we made before we want to add them*/
void	create_queue(t_queue **queue)
{
	t_links	*connected;

	connected = ROOM_CONNECTIONS; /*(*queue)->room->links, represents all conecting rooms of current room*/
	while (connected != NULL)
	{
		if (connected->room->visited == FALSE)
		{
			if (connected->room->path_id == FALSE || connected->room->type == START)
			{
				connected->room->visited = TRUE;
				connected->room->distance = CURRENT_QUEUE_ROOM_DISTANCE + 1;
				add_to_queue(queue, new_element(connected->room));
			}
			else if (connected->room->path_id != FALSE && CURRENT_QUEUE_ROOM->type != END)
				follow_path(queue, connected->room);
		}
		connected = connected->next;
	}
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
