/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_paths.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 12:35:05 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/17 15:53:04 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*this function resets all path_id values to 0*/
void	reset_path_ids(t_path_set **path_set)
{
	t_path_set	*probe_set;
	t_path		*probe_paths;

	probe_set = *path_set;
	while (probe_set != NULL)
	{
		probe_paths = probe_set->path;
		while (probe_paths != NULL)
		{
			if (probe_paths->room->path_id != FALSE)
				probe_paths->room->path_id = FALSE;
			probe_paths = probe_paths->next;
		}
		probe_set = probe_set->next;
	}
}
