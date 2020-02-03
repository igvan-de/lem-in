/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_paths.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 12:35:05 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/03 17:00:59 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*this function resets all path_id values to 0*/
// void	reset_path_ids(t_path_set **path_set)
// {
// 	t_path_set	*probe_set;
// 	t_path		*probe_paths;

// 	probe_set = *path_set;
// 	while (probe_set != NULL)
// 	{
// 		probe_paths = probe_set->path;
// 		while (probe_paths != NULL)
// 		{
// 			if (probe_paths->room->path_id != false)
// 				probe_paths->room->path_id = false;
// 			probe_paths = probe_paths->next;
// 		}
// 		probe_set = probe_set->next;
// 	}
// }

void	reset_path_ids(t_rooms **table, size_t size)
{
	size_t i;
	t_rooms *tmp;
	i = 0;
	tmp = NULL;
	while (i < size)
    {
		tmp = table[i];
        while (table[i] != NULL)
        {
			table[i]->path_id = 0;
            table[i] = table[i]->next;
        }
		table[i] = tmp;
        i++;
    }
}

/*this function resets all path_id values to 0*/
// void	reset_path_ids(t_path_set **path_set)
// {
// 	t_path_set	*probe_set;
// 	t_path		*probe_paths;

// 	probe_set = *path_set;
// 	while (probe_set != NULL)
// 	{
// 		probe_paths = probe_set->path;
// 		while (probe_paths != NULL)
// 		{
// 			if (probe_paths->room->path_id != false)
// 				probe_paths->room->path_id = false;
// 			probe_paths = probe_paths->next;
// 		}
// 		probe_set = probe_set->next;
// 	}
// }

/*this function resets the link->end type back to false if the value is true,
this for the reason the dont go back in start-end later in follow_shifts function*/
void	reset_link_value(t_path **start)
{
	t_links		*connected;

	connected = (*start)->room->links;
	while (connected != NULL)
	{
		if (connected->end == true)
			connected->end = false;
		connected = connected->next;
	}
}

void	undo_path(t_path_set **set)
{
	t_path_set	*probe_set;
	t_path		*probe_path;

	probe_set = *set;
	while (probe_set != NULL)
	{
			// probe_path->room->path_id = 0;
			// probe_path->room->towards = NULL;
			// probe_path->room->next = NULL;
		probe_path = probe_set->path;
		while (probe_path != NULL)
		{
			if (probe_path->next->room->path_id == probe_path->next->room->path_id)
				probe_path->room->links->shift = OFF;
			probe_set->path_size -= 1;
			probe_path = probe_path->previous;
		}
		probe_set = probe_set->next;
	}
}
