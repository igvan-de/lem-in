/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:23:56 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/09 16:26:31 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_table	*set_null(t_table *head)
{
	t_table *probe;

	probe = head;
	if (probe == NULL)
		return (NULL);
	while (probe != NULL)
	{
		probe->distance = 0;
		probe->visited = 0;
		if (probe->type == END || probe->type == START)
			probe->path_id = FALSE;
		probe = probe->next;
	}
	return (head);
}

static void		set_value(t_table **table, size_t size)
{
	size_t	i;
	t_table	**probe;

	i = 0;
	probe = table;
	while (i < size)
	{
		probe[i] = set_null(probe[i]);
		i++;
	}
}

int				bfs(t_ants **ants, t_table **table, size_t size)
{
	t_queue *queue;
	t_queue *start;
	t_links	*probe;

	queue = create_end(*ants);
	start = create_start(*ants);
	probe = queue->to->links;
	set_value(table, size);
	while (queue != NULL)
	{
		probe = queue->to->links;
		while (probe != NULL)
		{
			if (probe->to->visited == FALSE && probe->to->path == FALSE) //not sure if this is correct if we have paths that cross?
			{
				add_to_queue(&queue, new_element(probe->to));
				probe->to->visited = TRUE;
				if (probe->to->type != END)
					probe->to->distance = queue->to->distance + 1;
			}
			probe = probe->next;
		}
		// printf("queue->name = %s\tqueue->to->path_id = %d\n", queue->to->name, queue->to->path_id);
		// printf("queue->name = %s\tqueue->to->distance = %d\n", queue->to->name, queue->to->distance);
		// printf("===========\n");
		pop_out_queue(&queue);
	}
	if (start->to->visited == FALSE)
	{
		ft_putendl("There is no path from start to end");
		return (FALSE);
	}
	return (TRUE);
}
