/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:10:21 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/14 16:36:09 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/* Which steps are needed for breadth first search
	1. Set all values to NULL
		a. distance
		b. visited
	2. Find room with type END, because we want our BFS to calculate from end to start
	3. Probe through connections of current room (in the beginning room with type END)
		*WHEN TO PROBE TO NEXT ROOM
		1. if connected room isn't visited
		2. if connected room has an path_id
			- probe only to connected room if
				a. current room isn't room type END
				b. connected room is of the same path value
				c. follow direction of room according to path_id
					- towards of connected room
					- add_to_queue the room of the towards
					  with the same distance value as current room (only the first time)
					- while connected room has same path_id as current room and
					towards->room == connected->room add_to_queue with
						a. SUM=(connection->distance = current_room->distance)
					- if connected room hasn't the same path_id as current room add_to_queue with
						a. SUM=(connection->distance = current_room->distance + 1)
		*IF PROBING TO CONNECTED ROOM IS ALLOWED
		1. add connected room to queue
	4. Give value to connected room (only if its added to queue)
		a. SUM=(connection->distance = current_room->distance + 1)
		b. Set visited on TRUE (this because you don't want to look again to room you have already visited)
	5. stop bfs if there is no more possible path from end to start
	MAKE CODE MORE DYNAMIC, need to check if this will work
		1. should not add start in queue if current->room->from == connected->room->type == START
*/

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
	t_queue *test;

	set_value(rooms, size);
	queue = create_end(data);
	start = create_start(data);
	while (queue != NULL)
	{
		create_queue(&queue);
		test = queue;
		printf("============================\n");
		while (test != NULL)
		{
			printf("•••test = %s\t", test->room->name);
			printf("•••test->visisted = %d\t", test->room->visited);
			printf("•••test->distence = %d\n\n", test->room->distance);
			test = test->next;
		}
		if (queue->room->type == START)
		{
			free(queue);
			queue = NULL;
			return (TRUE);
		}
		pop_out_queue(&queue);
		printf("========AFTER POP=========\n");
		test = queue;
		while (test != NULL)
		{
			printf("test = %s\t", test->room->name);
			printf("test->visisted = %d\t", test->room->visited);
			printf("test->distence = %d\n\n", test->room->distance);
			test = test->next;
		}
	}
	if (start->room->visited == FALSE)
		return (FALSE);
	return (TRUE);
}
