/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:10:21 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/22 17:13:01 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This function set values distance and visited to 0 in all the rooms*/
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

/*This function probes through all rooms to set values to 0*/
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

/*This function calculates the distance values for every room,
it also checks for all possible paths*/
int			bfs(t_rooms **rooms, t_data *data, size_t size)
{
	t_queue	*queue;
	t_queue	*start;

	set_value(rooms, size);
	queue = create_end(data);
	start = create_start(data);
	while (queue != NULL)
	{
		if (queue->room->type == START)
		{
			free_queue(&queue);
			free_queue(&start);
			queue = NULL;
			return (TRUE);
		}
		create_queue(&queue);
		pop_out_queue(&queue);
	}
	if (start->room->visited == FALSE)
	{
		free_queue(&start);
		return (FALSE);
	}
	return (TRUE);
}
