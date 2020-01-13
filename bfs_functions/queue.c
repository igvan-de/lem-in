/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/13 15:20:04 by igvan-de      ########   odam.nl         */
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

/*This functions create the queue by adding the connecting rooms of current room to queue,
this only happens if the connected rooms meet the rules we made before we want to add them*/
void	create_queue(t_queue **queue)
{
	t_links	*connected;

	connected = ROOM_CONNECTIONS;
	while (connected != NULL)
	{
		if (connected->room->visited == FALSE)
		{
			if (connected->room->path_id == FALSE ||
			(connected->room->type == START && connected->room->towards != CURRENT_QUEUE_ROOM))
			{
				connected->room->visited = TRUE;
				connected->room->distance = CURRENT_QUEUE_ROOM_DISTANCE + 1;
				add_to_queue(queue, new_element(connected->room));
			}
			else if (connected->room->path_id == CURRENT_QUEUE_ROOM->path_id &&
			CURRENT_QUEUE_ROOM->towards == connected->room)
			{
				connected->room->visited = TRUE;
				connected->room->distance = CURRENT_QUEUE_ROOM->distance;
				add_to_queue(queue, new_element(connected->room));
			}
			else if (connected->room->path_id != CURRENT_QUEUE_ROOM->path_id && connected->room->type != START
			&& CURRENT_QUEUE_ROOM->type != END)
			{
				connected->room->visited = TRUE;
				connected->room->distance = CURRENT_QUEUE_ROOM->distance + 1;
				add_to_queue(queue, new_element(connected->room));
			}
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
