/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_paths.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 14:30:48 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/28 10:02:10 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// #include <stdio.h>

// static t_path_set	*begin_of_set(t_path_set *probe_set)
// {
// 	while (probe_set->previous != NULL)
// 	{
// 		printf("previous = %s\n", probe_set->previous->path->room->name);
// 		probe_set = probe_set->previous;
// 	}
// 	return (probe_set);
// }

static void	update_path_ids(t_path_set *path_sets)
{
	t_path_set	*probe_set;
	t_path		*probe_paths;

	probe_set = path_sets;
	while (probe_set != NULL)
	{
		probe_paths = probe_set->path;
		while (probe_paths != NULL)
		{
			probe_paths->room->path_id -= 1;
			probe_paths = probe_paths->next;
		}
		probe_set = probe_set->next;
	}
}

/*
** probe_paths probes through current path and returns false if current path
** doenst go have as last node room->type END else it returns true
*/

static bool	probe_paths(t_path *current_path)
{
	t_path	*probe_path;

	probe_path = current_path;
	while (probe_path != NULL)
	{
		if (probe_path->next == NULL && probe_path->room->type != END)
			return (false);
		probe_path = probe_path->next;
	}
	return (true);
}

/*
** check_paths probes through all paths to in best_path_set
** and removes current_path if that probe_paths return false
*/

void	check_paths(t_path_set **path_set)
{
	t_path_set	*fast_probe_set;
	t_path_set	*slow_probe_set;
	t_path		*current_path;

	fast_probe_set = *path_set;
	slow_probe_set = *path_set;
	while (fast_probe_set->next != NULL && slow_probe_set != NULL)
	{
		current_path = slow_probe_set->path;
		if (probe_paths(current_path) == false)
		{
			slow_probe_set->next = fast_probe_set;
			update_path_ids(fast_probe_set);
			free_path(&current_path);
		}
		if (fast_probe_set->next->next != NULL)
			fast_probe_set = fast_probe_set->next->next;
		slow_probe_set = slow_probe_set->next;
	}
}

		// 	if (current_path->next->room->path_id == 1)
		// 	{
		// 		*path_set = probe_set->next;
		// 		update_path_ids(*path_set);
		// 		free_path(&current_path);
		// 	}
		// 	else
		// 	{
		// 		if ((*path_set)->next->next != NULL)
		// 			(*path_set)->next = probe_set->next->next;
		// 		// print_path_set(probe_set);
		// 		// exit(-1);
		// 		update_path_ids(probe_set);
		// 		free_path(&current_path);
		// 		// probe_set = begin_of_set(probe_set);
		// 	}
		// }
