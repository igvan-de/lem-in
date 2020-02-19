/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shifts.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 15:00:36 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/19 15:19:17 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Follows shifts and adds connected rooms with shift value ON
** to path linked list. This to create a path, it gives also the path_id values
*/

void			follow_shifts(t_path **path, t_path_set *set)
{
	t_links	*connected;
	t_path	*get_last_room;

	get_last_room = (*path);
	while (get_last_room->next != NULL)
		get_last_room = get_last_room->next;
	if (get_last_room->room->type == START)
		PATH_ID += 1;
	if (get_last_room->room->type == END)
		return ;
	connected = CURRENT_PATH_ROOM_LINKS;
	while (connected != NULL)
	{
		if (CONNECTED_SHIFT == ON && (CONNECTED_ROOM_PATH_ID == false ||
		(connected->room->type == END && connected->end == false)))
		{
			connected->room->path_id = PATH_ID;
			add_to_path(path, new_room_to_path(connected->room), set);
			return (follow_shifts(path, set));
		}
		connected = connected->next;
	}
}

/*
** Shift links on or off in both directions for connected rooms
*/

void			set_link_shift(t_rooms **room, t_rooms **connected_room)
{
	t_links	*probe_rooms;

	probe_rooms = (*room)->links;
	while (probe_rooms != NULL)
	{
		if (probe_rooms->room == (*connected_room))
		{
			if (probe_rooms->shift == OFF)
				probe_rooms->shift = ON;
			else
				probe_rooms->shift = OFF;
		}
		probe_rooms = probe_rooms->next;
	}
}

/*
** Sets shifts of link
*/

bool			set_link_shifts(t_links *connected,
int current_distance, t_rooms **room)
{
	if (connected->room->distance == (current_distance - 1))
	{
		set_link_shift(room, &connected->room);
		set_link_shift(&connected->room, room);
		return (true);
	}
	return (false);
}

/*
** Sets shifts of branch
*/

bool			set_branch_shifts(t_links *connected, t_rooms **room)
{
	if (connected->room->branch != NULL &&
	connected->room != (*room)->towards
	&& connected->room->distance != (*room)->distance &&
	((*room)->distance - 1) == connected->room->branch->distance)
	{
		connected->room->distance = (*room)->distance;
		set_link_shift(room, &connected->room);
		set_link_shift(&connected->room, room);
		return (true);
	}
	return (false);
}
