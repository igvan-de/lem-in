/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_paths.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:04:44 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/09 15:55:11 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/* Which steps to follow for creating paths
	1. follow bfs values from high to low distance value only if distance - 1 smaller then
	   or is even to distance value of current rooms(in decreasing order)
		a. turn all shift values in the oppisite then they are when following bfs path
			- shift->ON becomes shift->OFF
			- shift->OFF becomes shift->ON
	2. follow all connections with shift ON
		*ONLY FOLLOW THOSE CONNECTIONS IF
		a. path_id is 0
		example "while(start->connections != NULL && connection->path_id == 0
		&& connection->shift == ON"
		b. Then continue following all connections with shift is ON
	3. function to calculate if new path(s) are quicker then old one(s)
		a. add_to_path_set, but only if the newly path(s) are quicker to move the ants
			1. remove all paths
			2. set all towards values to NULL (not sure if this is needed?)
			3. add new paths to set
*/

/*This function mallocs path struct and sets it first node to room with type START*/
static t_path	*set_start(t_data *data)
{
	t_path	*start;

	start = (t_path*)ft_memalloc(sizeof(t_path));
	start->room = data->start_room;
	return (start);
}

/*This function adds a new room at the end of linked list of existing path*/
static void	add_to_path(t_path **path, t_rooms *new_room)
{
	t_path	*path_rooms;

	path_rooms = *path;
	while (path_rooms != NULL)
		path_rooms = path_rooms->next;
	path_rooms->room = new_room;
}

/*This function fallows shifts and add connecting->rooms with shift value ON
to path linked list. This to create a path, it gives also the path_id values*/
static void	follow_shifts(t_path **path)
{
	t_links	*connected;

	PATH_ID += 1;
	connected = CURRENT_PATH_ROOM_LINKS;
	while (connected != NULL)
	{
		if (connected->shift == ON && connected->room->path_id == CURRENT_PATH_ROOM->path_id)
		{
			connected->room->path_id = PATH_ID;
			add_to_path(path, connected->room);
			connected = CURRENT_PATH_ROOM_LINKS;
		}
		connected = connected->next;
	}
}

/*This function follows the bfs values in decreasing order by a value of 1,
it also turn all shift values on or off in the oppiste value then current state*/
static void	follow_bfs(t_data *data)
/*CHECK!! not sure if t_rooms **rooms is needed to give as parameter to change values globally in program*/
{
	t_links	*connected;
	int		current_distance;

	connected = data->start_room->links;
	current_distance = connected->room->distance;
	while (connected)
	{
		if (current_distance == (connected->room->distance - 1)
		|| current_distance == connected->room->distance)
		{
			connected = connected->room->links;
			if (CONNECTED_ROOM_SHIFT == ON)
				CONNECTED_ROOM_SHIFT = OFF;
			else
				CONNECTED_ROOM_SHIFT = ON;
		}
		connected = connected->next;
	}
}

/*This function the hart of our path searching algorithm
from here we start fallowing the bfs values and the shift values,
also we save the paths and caluculate if the new finded paths are quicker to use then older paths*/
void		search_path(t_data *data)
{
	t_path	*path;

	path = set_start(data);
	follow_bfs(data);
	while (CONNECTED_ROOM->path_id == FALSE && CONNECTED_ROOM->links->shift == ON)
		follow_shifts(&path);
}
