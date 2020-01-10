/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_paths.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:04:44 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/10 15:36:24 by igvan-de      ########   odam.nl         */
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

/*this functions probes through connections of start to check if there's a connection
where the link->shift is ON*/
static int		check_start_connections(t_path *path)
{
	t_links	*connected;

	connected = path->room->links;
	while (connected != NULL)
	{
		if (CONNECTED_ROOM_SHIFT == ON && CONNECTED_ROOM_PATH_ID == FALSE)
			return (TRUE);
		connected = connected->next;
	}
	return (FALSE);
}

/*This function mallocs path struct and sets it first node to room with type START*/
static t_path	*set_start(t_data *data)
{
	t_path	*start;

	start = (t_path*)ft_memalloc(sizeof(t_path));
	start->room = data->start_room;
	return (start);
}

/*This function creates a t_path pointer of the new room which need to be added to path*/
t_path	*new_room_to_path(t_rooms *room)
{
	t_path	*new_room;

	new_room = (t_path*)ft_memalloc(sizeof(t_path));
	new_room->room = room;
	return (new_room);
}

/*This function adds a new room at the end of linked list of existing path*/
void		add_to_path(t_path **path, t_path *new_room)
{
	t_path	*path_rooms;

	path_rooms = *path;
	/*need to check if I assign the right values here!*/
	while (path_rooms->next != NULL)
		path_rooms = path_rooms->next;
	new_room->path_size = path_rooms->path_size + 1;
	path_rooms->room->towards = new_room->room;
	path_rooms->next = new_room;
}

/*This function the hart of our path searching algorithm
from here we start fallowing the bfs values and the shift values,
also we save the paths and caluculate if the new finded paths are quicker to use then older paths*/
void		search_path(t_data *data)
{
	t_path		*path;
	t_rooms		*start;

	path = set_start(data);
	start = data->start_room;
	follow_bfs(&start);
	while (check_start_connections(path) == TRUE)
		follow_shifts(&path);
	/*funtion to calculate if new founded paths are better to use*/
	save_paths(path);
}
