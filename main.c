/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/28 17:02:21 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	t_rooms		rooms;
	t_ants		ants;

	read_input(&rooms, &ants);
	printf("amount of ants = %d\n", ants.start);
	// while (rooms)
	// {
	// 	printf("roomname: ")
	// 	rooms = rooms->next;
	// }
	return (FALSE);
}
