/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:10:21 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/19 16:00:30 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Set values distance and visited to 0 in all the rooms
*/

static t_rooms	*set_to_null(t_rooms *head)
{
	t_rooms	*probe;

	probe = head;
	if (probe == NULL)
		return (NULL);
	while (probe != NULL)
	{
		probe->distance = 0;
		probe->visited = 0;
		probe = probe->next;
	}
	return (head);
}

/*
** Probes through all rooms to sets values to 0
*/

static void		set_value(t_rooms **rooms, size_t size)
{
	size_t	i;
	t_rooms	**probe;

	i = 0;
	probe = rooms;
	while (i < size)
	{
		probe[i] = set_to_null(probe[i]);
		i++;
	}
}

/*
** Calculates the distance value for every room
** and checks for all possible paths
*/

#include <stdio.h>
bool			bfs(t_rooms **rooms, t_data *data)
{
	t_queue	*queue;
	t_queue	*start;
	// t_queue *test;

	set_value(rooms, data->size);
	queue = create_end(data);
	start = create_start(data);
	while (queue != NULL)
	{
		create_queue(&queue);
		// test = queue;
		// printf("============================\n");
		// while (test != NULL)
		// {
		// 	printf("•••test = %s\t", test->room->name);
		// 	printf("•••test->visited = %d\t", test->room->visited);
		// 	printf("•••test->distance = %d\n\n", test->room->distance);
		// 	test = test->next;
		// }
		if (queue->room->type == START)
		{
			free_queue(&queue);
			free_queue(&start);
			return (true);
		}
		pop_out_queue(&queue);
		// /*place pop_out_queu function here*/
		// printf("========AFTER POP=========\n");
		// test = queue;
		// while (test != NULL)
		// {
		// 	printf("test = %s\t", test->room->name);
		// 	printf("test->visited = %d\t", test->room->visited);
		// 	printf("test->distance = %d\n\n", test->room->distance);
		// 	test = test->next;
		// }
	}
	if (start->room->visited == false)
	{
		free_queue(&start);
		return (false);
	}
	return (true);
}
