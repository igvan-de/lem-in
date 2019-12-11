/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   value.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 16:55:41 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/11 17:57:29 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_queue	*create_start(t_ants *ants)
{
	t_queue *start;

	start = (t_queue*)ft_memalloc(sizeof(t_queue));
	start->to = ants->begin;
	return (start);
}

t_queue	*create_end(t_ants *ants)
{
	t_queue *queue;

	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->to = ants->end;
	queue->to->visited = TRUE;
	return (queue);
}

t_queue	*new_element(t_table *pointer)
{
	t_queue	*queue;

	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->to = pointer;
	return (queue);
}

t_path_data	*get_end(t_path_data *path)
{
	t_path_data	*probe;

	if (path->room == NULL)
		return (path);
	probe = path;
	while (probe->room->type != END)
		probe = probe->next;
	return (probe);
}
