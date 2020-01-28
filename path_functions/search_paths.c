/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_paths.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:04:44 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/28 20:20:41 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This function mallocs path struct and sets it first node to room with type START*/
static t_path		*set_start(t_data *data)
{
	t_path	*start;
	t_links	*probe_links;

	start = (t_path*)ft_memalloc(sizeof(t_path));
	start->room = data->start_room;
	probe_links = start->room->links;
	if (start->room->towards != NULL && start->room->path_id != false)
	{
		if (start->room->towards->type == END && start->room->towards->path_id != false)
		{
			while (probe_links != NULL)
			{
				if (probe_links->room->type == END)
					probe_links->end = true;
				probe_links = probe_links->next;
			}
		}
	}
	return (start);
}

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
static bool			check_start_connections(t_path *path)
{
	t_links	*connected;

	connected = path->room->links;
	while (connected != NULL)
	{
		if (CONNECTED_SHIFT == ON && connected->end == false &&
		(CONNECTED_ROOM_PATH_ID == false || connected->room->type == END))
			return (true);
		connected = connected->next;
	}
	return (false);
}

/*This function the hart of our path searching algorithm
from here we start fallowing the bfs values and the shift values,
also we save the paths and calculate if the new finded paths are quicker to use then older paths*/
static t_path_set		*search_path(t_path_set **path_set, t_data *data)
{
	t_path_set	*path_sethhh;
	t_path_set	*set;
	t_path		*path;
	t_rooms		*start;

	path_sethhh = NULL;
	reset_path_ids(path_set);
	path = set_start(data);
	reset_link_value(&path);
	start = data->start_room;
	follow_bfs(&start);
	while (check_start_connections(path) == true)
	{
		set = new_path(path);
		follow_shifts(&path, set);
		save_paths(&path_sethhh, set);
		path = set_start(data);
	}
	free_path(&path);
	return (path_sethhh);
}

/*this function is the main for searching the path,
from here we will start calculating bfs and search all possible paths*/
void			create_paths_and_send_ants(t_rooms **rooms, t_data *data, size_t size)
{
	t_path_set	*new_path_set;
	t_path_set	*best_path_set;
	size_t		i;
	int			turns;

	i = 0;
	turns = 0;
	new_path_set = NULL;
	best_path_set = NULL;
	while (bfs(rooms, data, size) == true)
	{
		new_path_set = search_path(&new_path_set, data);
		if (turns == 0 || turns > calc_turn_amount(data, new_path_set))
		{
			best_path_set = new_path_set;
			turns = calc_turn_amount(data, best_path_set);
		}
		if (data->amount_ants_start == 1)
			break ;
	}
	// free_path_set(&best_path_set);
	print_path_set(best_path_set);
	exit(-1);
	if (best_path_set->path->room->type == START)
		best_path_set->path->room->ant_id = 1;
	send_ants(&data, &best_path_set, 1, turns);
	while (i < size)
	{
		free_rooms(&rooms[i]);
		i++;
	}
	free(rooms);
}
