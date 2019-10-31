/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/31 17:32:39 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// void	print_stuff(t_hash_table **rooms, t_ants **ants) //temporary test function
// {
// 	printf("amount of ants = %d\n", (*ants)->start);
// 	while (*rooms)
// 	{
// 		printf("Room: %s\t\tindex: %d\tx: %d\t\ty: %d\n",
// 		(*rooms)->data.name, (*rooms)->index, (*rooms)->data.x, (*rooms)->data.y);
// 		(*rooms) = (*rooms)->next;
// 	}
// }

int		main(int argc, char **argv)
{
	t_hashTable		*room;
	t_ants			*ants;

	ants = (t_ants*)ft_memalloc(sizeof(t_ants));
	read_input(&room, &ants);
	// print_stuff(&rooms, &ants); //temporary
	return (FALSE);
}
