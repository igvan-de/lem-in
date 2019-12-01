/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:23:56 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/01 18:34:55 by igvan-de      ########   odam.nl         */
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

void		bfs(t_ants **ants, t_table **table, size_t size)
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
			// printf("aan = %d\n", probe->aan);
			if (probe->to->visited == FALSE && probe->to->path_id == FALSE) //not sure if this is correct if we have paths that cross?
			{
				add_to_queue(&queue, new_element(probe->to));
				probe->to->visited = TRUE;
				probe->to->distance = queue->to->distance + 1;
				// printf("probe = %d\troom = %s\n", probe->aan, probe->to->name);
				// printf("probe->visited = %d\n", probe->to->visited);
				// printf("probe->distance = %d\n", probe->to->distance);
				// printf("===========\n");
			}
			probe = probe->next;
		}
		pop_out_queue(&queue);
	}
	if (start->to->visited == FALSE)
	{
		ft_putendl("There is no path from start to end");
		exit(0);
	}
}





// int				compare_node(t_node *previous, t_node *node)
// {
// 	if (previous == NULL || node == NULL)
// 		return (FALSE);
// 	if (previous->location.x == node->location.x && previous->location.y == node->location.y)
// 		return (TRUE);
// 	else
// 		return (FALSE);
// }

// void			remove_node(t_node **set, t_node *node)
// {
// 	t_node *tmp;
// 	t_node *ph;

// 	if (*set == NULL || node == NULL)
// 		return ;
// 	tmp = *set;
// 	if (compare_node(tmp, node) == TRUE)
// 	{
// 		*set = tmp->next;
// 		tmp->next = NULL;
// 		return ;
// 	}
// 	while (tmp->next)
// 	{
// 		ph = tmp->next;
// 		if (compare_node(ph, node) == TRUE)
// 		{
// 			tmp->next = ph->next;
// 			ph->next = NULL;
// 			return ;
// 		}
// 		tmp = tmp->next;
// 	}
// }
