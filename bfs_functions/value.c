/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   value.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 16:55:41 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/15 13:48:31 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Finds the room with type START
** so we can check if start is found in BFS
*/

t_queue	*create_start(t_data *data)
{
	t_queue *start;

	start = (t_queue*)ft_memalloc(sizeof(t_queue));
	start->room = data->start_room;
	start->next = NULL;
	return (start);
}

/*
** Finds the room with type END to start the queue so our BFS algorithm can
** work its way back from end to start
*/

t_queue	*create_end(t_data *data)
{
	t_queue *queue;

	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->room = data->end_room;
	queue->room->visited = true;
	queue->next = NULL;
	return (queue);
}

/*
** Creates a new element for the queue
*/

t_queue	*new_element(t_rooms *room)
{
	t_queue	*queue;

	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->room = room;
	queue->next = NULL;
	return (queue);
}
