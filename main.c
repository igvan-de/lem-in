/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/04 15:18:27 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_stuff(t_rooms *rooms, t_ants **ants) //temporary test function
{
	printf("%d ants need to get from start to end or they will be eaten by a dragon.\n", (*ants)->start);
	while (rooms)
	{
		printf("Room: %s\t\tx: %d\t\ty: %d\n",
		rooms->name, rooms->x, rooms->y);
		rooms = rooms->next;
	}
}

int		main(int argc, char **argv)
{
	t_table			**table;
	t_rooms			*rooms;
	t_ants			*ants;

	ants = (t_ants*)ft_memalloc(sizeof(t_ants));
	read_input(table, &rooms, &ants);
	//print_stuff(rooms, &ants); //temporary
	return (FALSE);
}
