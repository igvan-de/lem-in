/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_paths.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:04:44 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/08 17:44:10 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/* Which steps to follow for creating paths
	1. follow bfs values from high to low distance value only if distance - 1 smaller then current rooms(in decreasing order)
		a. turn all shift values in the oppisite then they are when following bfs path
			- shift->ON becomes shift->OFF
			- shift->OFF becomes shift->ON
	2. follow all connections with shift ON
		*ONLY FOLLOW THOSE CONNECTIONS IF
		a. path_id is 0
		b. possible_path = TRUE
		example "while(start->connections != NULL && connection->path_id == 0 && connection->shift == ON"
		1. Then continue following all connections with shift is ON
*/
