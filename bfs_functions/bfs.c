/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:23:56 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/10 16:08:26 by igvan-de      ########   odam.nl         */
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
			probe->path = FALSE;
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

int				bfs(t_ants **ants, t_table **table, size_t size, t_path_data *path)
{
	t_queue *queue;
	t_queue *start;

	queue = create_end(*ants);
	start = create_start(*ants);
	set_value(table, size);
	while (queue != NULL)
	{
		create_queue(&queue, path);
		pop_out_queue(&queue);
	}
	if (start->to->visited == FALSE)
	{
		ft_putendl("There is no path from start to end");
		return (FALSE);
	}
	return (TRUE);
}
