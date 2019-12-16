/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/16 18:03:35 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_links	*follow_direction(t_links *probe)
{
	t_table *tmp;

	tmp = probe->to->towards;
	while (tmp != NULL && tmp->type != END)
	{
		if (tmp->links->shift == OFF)
		{
			tmp->distance = probe->to->distance + 1;
		}
		tmp = tmp->towards;
	}
	printf("tmp = %s\n", tmp->links->to->name);
	printf("tmp = %s\tdistance = %d\n", tmp->links->to->name, tmp->distance);
	return (tmp->links);
}

void		create_queue(t_queue **queue)
{
	t_links		*probe;

	probe = (*queue)->to->links;
	if (probe->to->type == END)
		probe->to->visited = TRUE;
	while (probe != NULL)
	{
		if (probe->to->visited == FALSE && probe->to->towards == NULL) //not sure if this is correct if we have paths that cross?
		{
			add_to_queue(queue, new_element(probe->to));
			probe->to->visited = TRUE;
			if (probe->to->type != END)
				probe->to->distance = (*queue)->to->distance + 1;
		}
		else if (probe->to->path == TRUE)
		{
			probe->to->distance = (*queue)->to->distance + 1;
			probe = follow_direction(probe);
			printf("probe name  = %s\n", probe->to->name);
			break ;
			// printf("name = %s\tprobe->distance = %d\n", probe->to->name, probe->to->distance);
		}
		// if (probe->to->path == FALSE)
		probe = probe->next;
	}
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
	first_node = NULL;
	free(first_node);
}
