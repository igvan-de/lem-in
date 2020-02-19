/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_paths.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 12:35:05 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/15 13:49:46 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Loops through hashtable and resets all path_id values to 0
*/

void	reset_path_ids(t_rooms **table, size_t size)
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
			table[i] = table[i]->next;
		}
		table[i] = tmp;
		i++;
	}
}

/*
** Resets type of the link back to false
*/

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
