/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:23:56 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/14 17:32:35 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

//loop to end!!!!!!!!!!!
static t_table	*find_end(t_table **table)//, t_rooms *room)
{
	t_table *probe;
	int		i;

	probe = table[i];
	while (probe->)
		probe = probe->next;
	return (probe);
}


static void	add_to_queue(t_table *probe, int *queue, int i)
{
	if (probe->visited == FALSE)
	{
		probe->visited = TRUE;
		queue[i] = probe;
	}
}

void		bfs(t_table **table, size_t size)
{
	t_table *probe;
	int		i;
	int		queue[size];

	i = 0;
	probe = find_end(table);
	while(probe->links != NULL)
	{
		add_to_queue(probe, queue, i);
		i++;
		probe->links = probe->links->next;
	}
}
