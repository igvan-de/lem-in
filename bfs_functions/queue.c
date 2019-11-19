/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/19 14:12:11 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_queue	*create_end(t_ants *ants)
{
	t_queue *queue;
	
	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->to = ants->end;
	queue->to->visited = TRUE;
	return (queue);
}

t_queue	*create_start(t_ants *ants)
{
	t_queue *start;

	start = (t_queue*)ft_memalloc(sizeof(t_queue));
	start->to = ants->begin;
	return (start);
}

t_queue	*new_element(t_table *pointer)
{
	t_queue	*queue;

	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->to = pointer;
	return (queue);
}

void		add_to_queue(t_queue **queue, t_queue *new)
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

void		pop_out_queue(t_queue **queue)
{
	t_queue	*first_node;

	first_node = *queue;
	(*queue) = (*queue)->next;
	free(first_node);
}
