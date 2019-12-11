/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 12:40:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/11 18:13:22 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// static int	follow_direction(t_links *probe, t_path_data *path)
// {
// 	if (probe->to->visited == FALSE && probe->to->path == TRUE)
// 	{
// 		if (path->room->links->shift == ON)
// 		{
// 			path->room->links->shift = OFF;
// 			printf("path->shift = %d\n", path->room->links->shift);
// 		}
// 	}
// 		return (TRUE);
// 	return (FALSE);
// }

static int	check_direction(t_links *probe, t_path_data *path)
{
	if (path->from == NULL)
		return (TRUE);
	if (probe->to->path == FALSE && ft_strequ(probe->to->name, path->from->name) == FALSE)
		return (TRUE);
	return (FALSE);
}

void		create_queue(t_queue **queue, t_path_data *path)
{
	t_links		*probe;
	t_path_data *tmp;

	tmp = get_end(path);
	probe = (*queue)->to->links;
	while (probe != NULL)
	{
		if (probe->to->type == END)
			probe->to->visited = TRUE;
		if (probe->to->visited == FALSE && check_direction(probe, tmp) == TRUE) //not sure if this is correct if we have paths that cross?
		{
			printf("probe->name = %s\n", probe->to->name);
			add_to_queue(queue, new_element(probe->to));
			probe->to->visited = TRUE;
			if (probe->to->type != END)
				probe->to->distance = (*queue)->to->distance + 1;
		}
		// else if (follow_direction(probe, path) == TRUE)
		// {
		// 	printf("name = %s\tprobe->visited = %d\tprobe->path = %d\n", probe->to->name, probe->to->visited, probe->to->path);
		// 	add_to_queue(queue, new_element(probe->to));
		// 	probe->to->visited = TRUE;
		// 	if (probe->to->type != END)
		// 		probe->to->distance = (*queue)->to->distance + 1;
		// }
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
