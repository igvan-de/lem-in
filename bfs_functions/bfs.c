/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 12:23:56 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/05 20:54:31 by igvan-de      ########   odam.nl         */
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
		{
			probe->path = FALSE;
			// probe->towards = NULL;
		}
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

int				bfs(t_ants **ants, t_table **table, size_t size)
{
	t_queue *queue;
	t_queue *start;
	// t_queue *test;

	queue = create_end(*ants);
	start = create_start(*ants);
	set_value(table, size);
	while (queue != NULL)
	{
		create_queue(&queue);
		// test = queue;
		// printf("============QUEUE===========\n");
		// while (test != NULL)
		// {
		// 	printf("•••test = %s\t", test->to->name);
		// 	printf("•••test->visisted = %d\t", test->to->visited);
		// 	printf("•••test->distence = %d\n\n", test->to->distance);
		// 	test = test->next;
		// }
		// /*place pop_out_queu function here*/
		pop_out_queue(&queue);
		// printf("========AFTER POP=========\n");
		// test = queue;
		// while (test != NULL)
		// {
		// 	printf("test = %s\t", test->to->name);
		// 	printf("test->visisted = %d\t", test->to->visited);
		// 	printf("test->distence = %d\n\n", test->to->distance);
		// 	test = test->next;
		// }
		// printf("============================\n");
	}
	// if (start->to->visited == FALSE)
	// {
	// 	ft_putendl("There is no path from start to end");
	// 	return (FALSE);
	// }
	return (TRUE);
}

void			bfs_path(t_bfs **start, t_bfs *new)
{
	t_bfs	*path;

	path = *start;
	if (path == NULL || new == NULL)
		return ;
	while (path->next != NULL)
	{
		printf("bfs = %s\n", path->room->name);
		path = path->next;
	}
	new->room->from = path->room;
	path->next = new;
	path->room->bfs = TRUE;
	path->room->towards = new->room;
}

t_bfs	*follow_bfs(t_bfs *existing, t_links *connections)
{
	t_bfs	*new;

	new = (t_bfs*)ft_memalloc(sizeof(t_bfs)); //check if needed and why?!
	new->room = existing->room;
	while (connections != NULL)
	{
		if (connections->to->distance == (new->room->distance - 1))
		{
			new->room = connections->to;
			if (new->room->links->shift == ON)
				new->room->links->shift = OFF;
			else
				new->room->links->shift = ON;
		}
		connections = connections->next;
	}
	return (new);
}
