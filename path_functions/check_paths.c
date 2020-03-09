/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_paths.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 14:30:48 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/28 13:05:25 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

bool	check_paths(t_path_set **path_set)
{
	t_path_set	*probe_set;
	t_path		*current_path;

	probe_set = *path_set;
	while (probe_set != NULL)
	{
		current_path = probe_set->path;
		if (probe_paths(current_path) == false)
			return (false);
		probe_set = probe_set->next;
	}
	return (true);
}
