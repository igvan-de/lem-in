/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   follow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 15:00:36 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/27 14:23:05 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Checks if start and end are connected
** and turns on the shift values in both directions
*/

static bool		check_start_to_end(t_rooms **room, t_links *connected)
{
	if ((*room)->type == START && (*room)->distance == 1)
	{
		while (connected != NULL)
		{
			if (connected->room->type == END)
			{
				set_link_shift(room, &connected->room);
				set_link_shift(&connected->room, room);
				return (true);
			}
			connected = connected->next;
		}
	}
	return (false);
}

/*
** Creates a node for the new room
*/

t_path			*new_room_to_path(t_rooms *room)
{
	t_path	*new_room;

	new_room = (t_path*)ft_memalloc(sizeof(t_path));
	new_room->room = room;
	return (new_room);
}

/*
** Adds the new room at the end of the path
*/

void			add_to_path(t_path **path, t_path *new_room, t_path_set *set)
{
	t_path	*path_rooms;

	path_rooms = *path;
	while (path_rooms->next != NULL)
		path_rooms = path_rooms->next;
	set->path_size += 1;
	new_room->room->from = path_rooms->room;
	path_rooms->room->towards = new_room->room;
	path_rooms->next = new_room;
}

/*
** Follows the bfs values in decreasing order by a value of 1 and turns
** all on shifts off and all off shifts on
*/

void			follow_bfs(t_rooms **room)
{
	t_links	*connected;
	int		current_distance;

	if ((*room)->links == NULL || (*room)->type == END)
		return ;
	connected = (*room)->links;
	current_distance = (*room)->distance;
	if (check_start_to_end(room, connected) == true)
		return ;
	while (connected != NULL)
	{
		if (set_link_shifts(connected, current_distance, room) == true)
			return (follow_bfs(&connected->room));
		else if (set_branch_shifts(connected, room) == true)
			return (follow_bfs(&connected->room));
			// return (follow_bfs(&connected->room->branch));
		connected = connected->next;
	}
}
