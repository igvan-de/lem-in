/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:23:56 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/21 11:57:44 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	bfs(t_ants **ants)
{
	t_queue *queue;
	t_queue *start;
	t_links	*probe;

	queue = create_end(*ants);
	start = create_start(*ants);
	while (queue != NULL)
	{
		probe = queue->to->links;
		while (probe != NULL)
		{
			if (probe->to->visited == FALSE && probe->to->path_id == FALSE)
			{
				add_to_queue(&queue, new_element(probe->to));
				probe->to->visited = TRUE;
				probe->to->distance = queue->to->distance + 1;
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
