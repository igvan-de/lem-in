/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/10 16:36:48 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// static int	compare_rooms(t_table *probe, t_path_data *path)
// {
// 	t_table	*tmp;

// 	tmp = path->towards;
// 	if (probe == NULL || tmp == NULL)
// 		return (FALSE);
// 	while (tmp != NULL)
// 	{
// 		printf("probe = %s\tpath = %s\n", probe->name, tmp->name);
// 		if (ft_strequ(probe->name, tmp->name) == TRUE)
// 			return (TRUE);
// 		else
// 			return (FALSE);
// 		tmp = tmp->next;
// 	}
// 	return (FALSE);
// }

void		create_queue(t_queue **queue, t_path_data *path)
{
	t_links	*probe;
	t_path_data *tmp;

	tmp = path;
	probe = (*queue)->to->links;
	while (probe != NULL)
	{
		if (probe->to->visited == FALSE && path->from == NULL) //not sure if this is correct if we have paths that cross?
		{
			printf("probe->name = %s\n", probe->to->name);
			// while (path->towards != NULL)
			// 	probe = path->towards->links;
			add_to_queue(queue, new_element(probe->to));
			probe->to->visited = TRUE;
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
