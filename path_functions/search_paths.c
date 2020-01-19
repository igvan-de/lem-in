/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_paths.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:04:44 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/17 17:30:36 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*this function creates new space for */
static t_path_set	*new_path(t_path *path)
{
	t_path_set	*new_path;

	new_path = (t_path_set*)ft_memalloc(sizeof(t_path_set));
	new_path->path = path;
	new_path->path_size = 0;
	return (new_path);
}

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
static int		search_path(t_path_set **old_path_set, t_data *data, int turns)
{
	t_path_set	*new_path_set;
	t_path_set	*set;
	t_path		*path;
	t_rooms		*start;

	new_path_set = NULL;
	path = set_start(data);
	start = data->start_room;
	reset_path_ids(old_path_set);
	follow_bfs(&start);
	while (check_start_connections(path) == TRUE)
	{
		set = new_path(path);
		follow_shifts(&path, set);
		save_paths(&new_path_set, set);
		path = set_start(data);
	}
	if (turns == 0 || turns > calc_turn_amount(data, new_path_set))
	{
		*old_path_set = new_path_set;
		turns = calc_turn_amount(data, new_path_set);
	}
	print_path_set(*old_path_set);
	return (turns);
}

/*this function is the main for searching the path,
from here we will start calculating bfs and search all possible paths*/
void			create_paths_and_send_ants(t_rooms **rooms, t_data *data, size_t size)
{
	t_path_set	*old_path_set;

	old_path_set = NULL;
	while (bfs(rooms, data, size) == TRUE)
	{
		data->turns = search_path(&old_path_set, data, data->turns);
		if (data->amount_ants_start == 1)
			break ;
	}
	if (old_path_set->path->room->type == START)
		old_path_set->path->room->ant_id = 1;
	send_ants(&data, &old_path_set, 1);
}
