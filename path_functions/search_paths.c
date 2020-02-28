/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_paths.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:04:44 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/28 12:55:34 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Allocates path struct and sets it first node to room with type START
*/

static	t_path		*set_start(t_data *data)
{
	t_path	*start;
	t_links	*probe_links;

	start = (t_path*)ft_memalloc(sizeof(t_path));
	start->room = data->start_room;
	probe_links = start->room->links;
	if (start->room->towards != NULL && start->room->path_id != false)
	{
		if (start->room->towards->type == END &&
		start->room->towards->path_id != false)
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

/*
** Allocates new path
*/

static	t_path_set	*new_path(t_path *path)
{
	t_path_set	*new_path;

	new_path = (t_path_set*)ft_memalloc(sizeof(t_path_set));
	new_path->path = path;
	new_path->path_size = 0;
	return (new_path);
}

/*
** Iterates through start links to check if there's a connection
** where the link->shift is ON
*/

static	bool			check_start_connections(t_path *path)
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

/*
** The hart of our path searching algorithm, starts following
** the bfs and shift values and saves the found paths
*/

static	t_path_set	*search_path(t_data *data)
{
	t_path_set	*new_path_set;
	t_path_set	*set;
	t_path		*path;
	t_rooms		*start;

	new_path_set = NULL;
	path = set_start(data);
	reset_link_value(&path);
	start = data->start_room;
	follow_bfs(&start);
	while (check_start_connections(path) == true)
	{
		set = new_path(path);
		follow_shifts(&path, set);
		save_paths(&new_path_set, set);
		path = set_start(data);
	}
	free_path(&path);
	return (new_path_set);
}

/*
** Calculates if new found paths are faster than previous ones
*/

bool				calculate_path(t_path_set *old_path_set,
t_path_set **best_path_set, t_data *data)
{
	if (check_paths(&old_path_set) == false)
	{
		free_path_set(&old_path_set);
		return (false);
	}
	if (data->turns == 0 || data->turns > calc_turn_amount(data, old_path_set))
	{
		free_path_set(best_path_set);
		*best_path_set = old_path_set;
		data->turns = calc_turn_amount(data, *best_path_set);
		return (true);
	}
	free_path_set(&old_path_set);
	return (false);
}

/*
** Runs bfs and searches all possible new paths
*/

void				create_paths_and_send_ants(t_rooms **rooms,
t_data *data)
{
	t_path_set	*old_path_set;
	t_path_set	*best_path_set;

	old_path_set = NULL;
	best_path_set = NULL;
	while (bfs(rooms, data) == true)
	{
		reset_path_ids(rooms, data->size);
		old_path_set = search_path(data);
		if (calculate_path(old_path_set, &best_path_set, data) == false)
			break ;
		if (data->amount_ants_start == 1)
			break ;
	}
	if (best_path_set->path->room->type == START)
		best_path_set->path->room->ant_id = 1;
	send_ants(&data, &best_path_set);
	free_table(rooms, data);
	free(rooms);
}

void	reset_values(t_rooms **table, size_t size)
{
	size_t	i;
	t_rooms	*tmp;

	i = 0;
	tmp = NULL;
	while (i < size)
	{
		tmp = table[i];
		while (table[i] != NULL)
		{
			table[i]->path_id = 0;
			table[i]->distance = 0;
			table[i]->visited = 0;
			table[i]->ant_id = 0;
			table[i]->towards = NULL;
			table[i]->from = NULL;
			table[i]->branch = NULL;
			table[i] = table[i]->next;
		}
		table[i] = tmp;
		i++;
	}
}
