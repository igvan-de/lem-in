/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_print.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 14:54:30 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/04 17:09:28 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


/*===============DELETE THIS FILE!!================*/
#include "lemin.h"
#include <stdio.h> 

void	print_rooms(t_rooms *rooms, t_ants **ants)
{
	printf("%d ants need to get from start to end or they will be eaten by a dragon.\n", (*ants)->start);
	while (rooms)
	{
		printf("Room: %s\t\tx: %d\t\ty: %d\n",
		rooms->name, rooms->x, rooms->y);
		rooms = rooms->next;
	}
}

void	print_hash(t_table **table, size_t size)
{
	int i;

	i = 0;
	while (i < size)
	{
		while (table[i] != NULL)
		{
			printf("hash[%d] = %s\n", i, table[i]->name);
			table[i] = table[i]->next;
		}
		i++;
	}
}
