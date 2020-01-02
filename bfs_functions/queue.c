/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/02 17:30:04 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_direction(t_links *probe, t_queue *node)
{
	printf("node = %s\n", node->to->name);
	printf("probe = %s\n", probe->to->name);
	if (probe->to == node->to->from)
	{
		if (node->to->from != NULL)
		{
			printf("node = %s\n", node->to->from->name);
			if (node->to->from->towards != NULL)
				printf("towards = %s\n", node->to->from->towards->name);
			if (node->to->from->towards == node->to) //|| node->to->towards->type == END)
				return (TRUE);
		}
	}
	return (FALSE);
}

void		create_queue(t_queue **queue)
{
	t_links		*probe;

	probe = (*queue)->to->links;
	printf("tmp = %s\n", (*queue)->to->name); //remove
	if (probe->to->type == END)
		probe->to->visited = TRUE;
	while (probe != NULL && (*queue)->to->type == END)
	{
		if (probe->to->visited == FALSE && probe->to->path == FALSE && check_direction(probe, *queue) == FALSE)
		{
			printf("probe name  = %s\tvisited = %d\n", probe->to->name, probe->to->visited);
			add_to_queue(queue, new_element(probe->to));
			probe->to->visited = TRUE; // Check why if this is the right place in code for this!!
			if (probe->to->type != END) // Check why if this is the right place in code for this!!
				probe->to->distance = (*queue)->to->distance + 1; // CHeck why if this is the right place in code for this!!
		}
		probe = probe->next;
	}
	while (probe != NULL && (*queue)->to->type != END)
	{
		if (probe->to->visited == FALSE && probe->to->path == FALSE && check_direction(probe, *queue) == FALSE)
		{
			printf("probe name  = %s\tvisited = %d\n", probe->to->name, probe->to->visited);
			add_to_queue(queue, new_element(probe->to));
			probe->to->visited = TRUE; // Check why if this is the right place in code for this!!
			if (probe->to->type != END) // Check why if this is the right place in code for this!!
				probe->to->distance = (*queue)->to->distance + 1; // CHeck why if this is the right place in code for this!!
		}
		else if (probe->to->visited == FALSE && probe->to->path == TRUE && check_direction(probe, *queue) == FALSE)
		{
			probe->to->visited = TRUE;
			probe->to->distance = (*queue)->to->distance + 1;
			printf("name = %s\ttmp->distance = %d\n", probe->to->name, probe->to->distance);
			add_to_queue(queue, new_element(probe->to));
		}
		printf("type = %s\t type->visited = %d\n", probe->to->name, probe->to->visited);
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
