/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_paths.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 14:30:48 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/27 14:48:48 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

void	check_paths(t_path_set *path_set)
{
	t_path_set	*probe_set;
	t_path		*current_path;

	probe_set = path_set;
	while (probe_set != NULL)
	{
		current_path = probe_set->path;
		if (probe_paths(current_path) == false)
			free_path(&current_path);
		probe_set = probe_set->next;
	}
}
