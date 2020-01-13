/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   follow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 15:00:36 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/13 21:36:15 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This function creates a t_path pointer of the new room which need to be added to path*/
static t_path		*new_room_to_path(t_rooms *room)
{
	t_path	*new_room;

	new_room = (t_path*)ft_memalloc(sizeof(t_path));
	new_room->room = room;
	return (new_room);
}

/*This function adds a new room at the end of linked list of existing path*/
static void			add_to_path(t_path **path, t_path *new_room)
{
	t_path	*path_rooms;

	path_rooms = *path;
	while (path_rooms->next != NULL)
		path_rooms = path_rooms->next;
	new_room->room->from = path_rooms->room;
	path_rooms->room->towards = new_room->room;
	path_rooms->next = new_room;
}

/*This function fallows shifts and add connecting->rooms with shift value ON
to path linked list. This to create a path, it gives also the path_id values*/
void				follow_shifts(t_path **path)
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
		if (CONNECTED_SHIFT == ON && CONNECTED_ROOM_PATH_ID == FALSE)
		{
			if (connected->room->type != END)
				connected->room->path_id = PATH_ID;
			add_to_path(path, new_room_to_path(connected->room));
			return (follow_shifts(path));
		}
		connected = connected->next;
	}
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
	while (connected != NULL)
	{
		if (connected->room->distance == (current_distance - 1) && CONNECTED_SHIFT == FALSE)
		{
			printf("name = %s\tdistance = %d\n", connected->room->name, connected->room->distance);
			if (CONNECTED_SHIFT == ON && connected->room->type != END)
				CONNECTED_SHIFT = OFF;
			else
				CONNECTED_SHIFT = ON;
			return (follow_bfs(&connected->room));
		}
		else if (connected->room->distance == current_distance &&
		CONNECTED_SHIFT == ON && connected->room->towards == *room)
		{
			printf("name 2 = %s\tdistance = %d\n", connected->room->name, connected->room->distance);
			if (connected->room->links->shift == ON && connected->room->towards == *room)
				connected->room->links->shift = OFF;
			return (follow_bfs(&connected->room));
		}
		connected = connected->next;
	}
}
