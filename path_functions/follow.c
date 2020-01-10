/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   follow.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 15:00:36 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/10 17:38:53 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This function fallows shifts and add connecting->rooms with shift value ON
to path linked list. This to create a path, it gives also the path_id values*/
void	follow_shifts(t_path **path)
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
		/*will get problem with overlapping paths,
		need to set path_id to 0 if shift is turned off!*/
		if (CONNECTED_ROOM_SHIFT == ON && CONNECTED_ROOM_PATH_ID == FALSE)
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
void	follow_bfs(t_rooms **room)
{
	t_links	*connected;
	int		current_distance;

	if ((*room)->links == NULL)
		return ;
	connected = (*room)->links;
	current_distance = (*room)->distance;
	while (connected != NULL)
	{
		if (connected->room->distance == (current_distance - 1)
		|| (current_distance == connected->room->distance && CONNECTED_ROOM_SHIFT == OFF))
		{
			if (CONNECTED_ROOM_SHIFT == ON)
				CONNECTED_ROOM_SHIFT = OFF;
			else
				CONNECTED_ROOM_SHIFT = ON;
			return (follow_bfs(&connected->room));
		}
		connected = connected->next;
	}
}
