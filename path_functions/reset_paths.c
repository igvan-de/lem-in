/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_paths.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 12:35:05 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/20 12:21:57 by igvan-de      ########   odam.nl         */
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
			if (probe_paths->room->path_id != false)
				probe_paths->room->path_id = false;
			probe_paths = probe_paths->next;
		}
		probe_set = probe_set->next;
	}
}

/*this function resets the link->end type back to false if the value is true,
this for the reason the dont go back in start-end later in follow_shifts function*/
void	reset_link_value(t_path **start)
{
	t_links	*connected;

	connected = (*start)->room->links;
	while (connected != NULL)
	{
		if (connected->end == true)
			connected->end = false;
		connected = connected->next;
	}
}
