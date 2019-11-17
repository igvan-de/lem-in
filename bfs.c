/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:23:56 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/17 17:02:31 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_queue	*create_end(t_ants *ants)
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
	printf("link = %p\n", queue->links->to);
	return (queue);
}

static void		add_to_queue(t_queue **queue, t_queue *new)
{
	t_queue	*probe;

	if (new == NULL)
		return ;
	printf("new = %p\n", new->links->to);
	/*==MIGHT NOT BE NEEDED==*/
	if ((*queue) == NULL)
	{
		(*queue) = new;
		return ;
	}
	/*=======================*/
	probe = *queue;
	while (probe->next != NULL)
	{
		printf("probe = %s\n", probe->table->name);
		probe = probe->next;
	}
	probe->next = new;
}

void			bfs(t_ants *ants)
{
	t_queue *queue;
	t_links	*probe;

	queue = create_end(ants);
	printf("queue->end = %p\n", queue->table);
	probe = queue->table->links;
	while (probe != NULL)
	{
		if (probe->to->visited == FALSE)
		{
			printf("queue->link = %s with pointer = %p\n", probe->to->name, probe->to);
			add_to_queue(&queue, new_element(probe));
			probe->to->visited = TRUE;
			probe->to->distance = probe->to->distance + 1;
		}
		probe = probe->next;
	}
	printf("queue = %p\n", queue->table);
	while (queue != NULL)
	{
		printf("queue->next = %p\n", queue->table);
		queue = queue->next;
	}
}
