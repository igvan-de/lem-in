/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/11 15:02:21 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_direction(t_links *probe, t_path_data *path)
{
	if (probe == NULL || path->from == NULL)
		return (FALSE);
	if (probe->to->path == FALSE && ft_strequ(probe->to->name, path->from->name) == FALSE)
		return (FALSE);
	return (TRUE);
}

void		create_queue(t_queue **queue, t_path_data *path)
{
	t_links		*probe;
	t_path_data *tmp;

	tmp = get_end(path);
	probe = (*queue)->to->links;
	while (probe != NULL)
	{
		printf("name = %s\tprobe->visited = %d\n", probe->to->name, probe->to->visited);
		if (probe->to->visited == FALSE && check_direction(probe, tmp) == FALSE) //not sure if this is correct if we have paths that cross?
		{
			printf("probe->name = %s\n", probe->to->name);
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
