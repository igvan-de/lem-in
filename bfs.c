/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:23:56 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/16 19:24:11 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_queue	*end(t_ants *ants)
{
	t_queue *queue;
	
	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->table = ants->end;
	return (queue);
}

static t_queue	*new_element(t_links *pointer)
{
	t_queue	*queue;

	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->links = pointer;
	printf("link = %s\n", queue->links->to->name);
	return (queue);
}

static void		add_to_queue(t_queue **queue, t_queue *new)
{
	t_queue	*probe;

	if (new == NULL)
		return ;
	/*==MIGHT NOT BE NEEDED==*/
	// if ((*queue) == NULL)
	// {
	// 	(*queue) = new;
	// 	return ;
	// }
	/*=======================*/
	probe = *queue;
	while (probe->next != NULL)
		probe = probe->next;
	probe->next = new;
}

void			bfs(t_table **table, t_ants *ants, size_t size)
{
	t_queue *queue;
	
	queue = end(ants);
	while (queue->table->links != NULL)
	{
		if (queue->table->links->to->visited == FALSE)
		{
			printf("queue->table = %s\n", queue->table->name);
			add_to_queue(&queue, new_element(queue->table->links));
			queue->table->links->to->visited = TRUE;
			queue->table->links->to->distance = queue->table->links->to->distance + 1;
		}
		queue->table->links = queue->table->links->next;
	}
}
