/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/13 16:42:25 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	follow_direction(t_links *probe)
{
	// if (probe->to->towards != NULL)
	// {
	// 	printf("name = %s\tpath = %d\n", probe->to->name, probe->to->path);
	// 	printf("towards = %s\n", probe->to->towards->name);
	// }
	if (probe->to->visited == FALSE && probe->to->path == TRUE &&
	probe->to->towards->type != END)
	{
		if (probe->to->links->shift == ON)
		{
			probe->to->links->shift = OFF;
			printf("path->shift = %d\n", probe->to->links->shift);
		}
		return (TRUE);
	}
	return (FALSE);
}

static int	check_towards(t_links *probe)
{
	if (probe->to->towards == NULL)
		return (TRUE);
	return (FALSE);
}

void		create_queue(t_queue **queue)
{
	t_links		*probe;

	probe = (*queue)->to->links;
	while (probe != NULL)
	{
		if (probe->to->type == END)
			probe->to->visited = TRUE;
		if (probe->to->visited == FALSE && check_towards(probe) == TRUE) //not sure if this is correct if we have paths that cross?
		{
			printf("probe->name = %s\n", probe->to->name);
			add_to_queue(queue, new_element(probe->to));
			probe->to->visited = TRUE;
			if (probe->to->type != END)
				probe->to->distance = (*queue)->to->distance + 1;
		}
		else if (follow_direction(probe) == TRUE)
		{
			printf("name = %s\tprobe->visited = %d\tprobe->path = %d\tprobe->distance = %d\n", probe->to->name, probe->to->visited, probe->to->path, probe->to->distance);
			printf("towards->distance = %d\n", probe->to->towards->distance);
			if (probe->shift == OFF && probe->to->distance == probe->to->towards->distance)
			{
				add_to_queue(queue, new_element(probe->to));
				probe->to->visited = TRUE;
			}
			if (probe->to->type != END)
				probe->to->distance = (*queue)->to->distance + 1;
		}
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
