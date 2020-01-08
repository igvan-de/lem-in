/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 15:10:21 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/08 17:44:58 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/* Which steps are needed for breadth first search
	1. Set all values to NULL
	2. Find room with type END
	3. Probe through connections of current room (in the beginning room with type END)
		*WHEN TO PROBE TO NEXT ROOM
		1. if connected room isn't visited
		2. if connected room has an path_id
			- probe only to connected room
				a. current room isn't room type END
				b. connected room is of the same path value
				c. follow direction of room according to path_id
					- towards of connected room
		*IF PROBING TO CONNECTED ROOM IS ALLOWED
		1. add connected room to queue
	4. Give value to connected room (only if its added to queue)
		a. SUM=(connection->distance = current_room->distance + 1)
		b. Set visited on TRUE (this because you don't want to look again to room you have already visited)
*/
