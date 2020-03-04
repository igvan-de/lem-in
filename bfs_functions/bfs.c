/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:10:21 by igvan-de       #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2020/03/04 19:35:01 by ygroenev      ########   odam.nl         */
=======
/*   Updated: 2020/03/04 17:19:02 by igvan-de      ########   odam.nl         */
>>>>>>> f7d98ae83846656d51a7ab3fbc2416bb95436bbc
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

#include <stdio.h> //remove
bool			bfs(t_rooms **rooms, t_data *data)
{
	t_queue	*queue;
	t_queue	*start;

	set_value(rooms, data->size);
	queue = create_end(data);
	start = create_start(data);
	while (queue != NULL)
	{
		create_queue(&queue);
		if (queue->room->type == START)
		{
			free_queue(&queue);
			free_queue(&start);
			return (true);
		}
		pop_out_queue(&queue);
	}
	if (start->room->visited == false)
	{
		free_queue(&start);
		return (false);
	}
	return (true);
}
