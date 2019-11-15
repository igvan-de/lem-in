/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:23:56 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/15 18:41:33 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	add_to_queue(t_queue **queue, t_table *new)
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

void		bfs(t_table **table, t_ants *ants, size_t size)
{
	t_queue *queue;

	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue = ants->end;
	while(queue->links->to != NULL)
	{
		printf("probe->name = %p\n", queue);
		if (queue->to->visited == FALSE)
		{
			print_hash(table, size);
			add_to_queue(&queue, queue->links->to);
			queue->to->visited = TRUE;
			queue->to->distance = queue->to->distance + 1;
		}
		queue->links = queue->links->next;
	}
}
