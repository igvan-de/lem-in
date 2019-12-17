/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/17 14:27:14 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	follow_direction(t_queue **queue, t_links *probe)
{
	t_table *tmp;

	tmp = probe->to->towards;
	while (tmp != NULL && tmp->type != END)
	{
		if (tmp->links->shift == OFF)
		{
			tmp->links->to->distance = probe->to->distance + 1;
			tmp->visited = TRUE;
			printf("tmp = %s\tdistance = %d\n", tmp->name, tmp->distance);
			add_to_queue(queue, new_element(tmp->links->to));

		}
		tmp = tmp->towards;
	}
}

static int	check_towards(t_links *probe)
{
	if (probe->to->towards == NULL)
		return (FALSE);
	if (probe->to->towards->type == END)
		return (TRUE);
	return (FALSE);
}

void		create_queue(t_queue **queue)
{
	t_links		*probe;

	probe = (*queue)->to->links;
	if (probe->to->type == END)
		probe->to->visited = TRUE;
	while (probe != NULL)
	{
		if (probe->to->visited == FALSE && check_towards(probe) == FALSE)
		{
			printf("probe name  = %s\tvisited = %d\n", probe->to->name, probe->to->visited);
			add_to_queue(queue, new_element(probe->to));
			probe->to->visited = TRUE;
			if (probe->to->type != END)
				probe->to->distance = (*queue)->to->distance + 1;
		}
		else if (probe->to->path == TRUE && check_towards(probe) == FALSE)
		{
			// probe->to->distance = (*queue)->to->distance + 1;
			follow_direction(queue, probe);
			printf("name = %s\ttmp->distance = %d\n", probe->to->name, probe->to->distance);
		}
		probe = probe->next;
	}
}

void	add_to_queue(t_queue **queue, t_queue *new)
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
