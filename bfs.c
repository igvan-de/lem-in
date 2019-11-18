/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:23:56 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/18 17:09:41 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_queue	*create_end(t_ants *ants)
{
	t_queue *queue;
	
	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->to = ants->end;
	queue->to->visited = TRUE; //check if this is the right place here!!
	return (queue);
}

static t_queue	*new_element(t_table *pointer)
{
	t_queue	*queue;

	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->to = pointer;
	return (queue);
}

static void		add_to_queue(t_queue **queue, t_queue *new)
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

static void		pop_out_queue(t_queue **queue)
{
	t_table	*first_node;

	first_node = (*queue)->to;
	(*queue) = (*queue)->next;
	free(first_node);
}

void			bfs(t_ants *ants)
{
	t_queue *queue;
	t_table	*probe;
	t_queue *test; //remove!!

	queue = create_end(ants);
	while (queue != NULL)
	{
		probe = queue->to;
		printf("queue value = %s\n", probe->links->to->name);
		while (probe->links != NULL)
		{
			if (probe->links->to->visited == FALSE)
			{
				add_to_queue(&queue, new_element(probe->links->to));
				probe->links->to->visited = TRUE;
				probe->links->to->distance = queue->to->distance + 1;
			}
			printf("probe %s\n", probe->links->to->name);
			probe->links = probe->links->next;
		}
		test = queue;
		while (test != NULL)
		{
			printf("test = %s\t", test->to->name);
			printf("test->visisted = %d\t", test->to->visited);
			printf("test->distence = %d\n\n", test->to->distance);
			test = test->next;
		}
		printf("============================\n");
		pop_out_queue(&queue);
		printf("========AFTER POP=========\n");
		test = queue;
		while (test != NULL)
		{
			printf("test = %s\t", test->to->name);
			printf("test->visisted = %d\t", test->to->visited);
			printf("test->distence = %d\n\n", test->to->distance);
			test = test->next;
		}
	}
	// while (queue != NULL)
	// {
	// 	printf("queue = %s\t", queue->to->name);
	// 	printf("queue->visited = %d\n", queue->to->visited);
	// 	printf("queue->distance = %d\n", queue->to->distance);
	// 	queue = queue->next;
	// }
}
