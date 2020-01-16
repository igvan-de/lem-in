/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_paths.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:04:44 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/16 13:59:23 by igvan-de      ########   odam.nl         */
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
		if (CONNECTED_SHIFT == ON && CONNECTED_ROOM_PATH_ID == FALSE)
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

/*This function the hart of our path searching algorithm
from here we start fallowing the bfs values and the shift values,
also we save the paths and caluculate if the new finded paths are quicker to use then older paths*/
static void		search_path(t_path_set **old_path_set, t_data *data)
{
	t_path_set	*new_path_set;
	t_path		*path;
	t_rooms		*start;

	new_path_set = NULL;
	path = set_start(data);
	start = data->start_room;
	reset_path_ids(old_path_set);
	follow_bfs(&start);
	while (check_start_connections(path) == TRUE)
	{
		follow_shifts(&path);
		save_paths(&new_path_set, path);
		path = set_start(data);
	}
	*old_path_set = new_path_set;
	print_path_set(*old_path_set);
}

/*this function is the main for searching the path,
from here we will start calculating bfs and search all possible paths*/
void			create_paths(t_rooms **rooms, t_data *data, size_t size)
{
	t_path_set	*old_path_set;

	old_path_set = NULL;
	while (bfs(rooms, data, size) == TRUE)
		search_path(&old_path_set, data);
}
