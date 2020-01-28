/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   follow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 15:00:36 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/28 12:05:56 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This function creates a t_path pointer of the new room which need to be added to path*/
static t_path	*new_room_to_path(t_rooms *room)
{
	t_path	*new_room;

	new_room = (t_path*)ft_memalloc(sizeof(t_path));
	new_room->room = room;
	return (new_room);
}

/*This function adds a new room at the end of linked list of existing path*/
static void		add_to_path(t_path **path, t_path *new_room, t_path_set *set)
{
	t_path	*path_rooms;

	path_rooms = *path;
	while (path_rooms->next != NULL)
		path_rooms = path_rooms->next;
	set->path_size += 1;
	new_room->room->from = path_rooms->room;
	path_rooms->room->towards = new_room->room;
	path_rooms->next = new_room;
	printf("room->name = %s\tnext->room = %s\troom->distance = %d\tpath_id = %d\n",
	path_rooms->room->name, path_rooms->next->room->name, path_rooms->room->distance, path_rooms->room->path_id);
}

/*this function shift links on or off in both direction for connected rooms*/
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

/*This function fallows shifts and add connecting->rooms with shift value ON
to path linked list. This to create a path, it gives also the path_id values*/
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
	// {
	// 	ft_putendl("");
	// 	print_path(*path);
		return ;
	// }
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

/*this function check if start is connected to end and turn on the shift values in both directions*/
static bool			check_start_to_end(t_rooms **room, t_links *connected)
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

/*This function follows the bfs values in decreasing order by a value of 1,
it also turn all shift values on or off in the oppiste value then current state*/
void				follow_bfs(t_rooms **room)
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
		if (connected->room->distance == (current_distance - 1) && connected->room->from != *room)
		{
			set_link_shift(room, &connected->room);
			set_link_shift(&connected->room, room);
			return (follow_bfs(&connected->room));
		}
		else if (connected->room->branch != NULL && connected->room != (*room)->towards
		&& connected->room->distance != (*room)->distance && ((*room)->distance- 1) == connected->room->branch->distance)
		{
			// printf("branch->name = %s\tbranche->distance =%d\n", connected->room->branch->name, connected->room->branch->distance);
			connected->room->distance = (*room)->distance;
			set_link_shift(room, &connected->room);
			set_link_shift(&connected->room, room);
			return (follow_bfs(&connected->room));
		}
		connected = connected->next;
	}
}
