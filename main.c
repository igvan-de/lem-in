/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/30 15:02:50 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_stuff(t_rooms **rooms, t_ants **ants) //temporary test function
{
	printf("%d ants need to get from start to end or they'll be eaten by a dragon!\n\n", (*ants)->start);
	printf("Index\tRoom\tX\tY\n");
	while (*rooms)
	{
		printf("%d\t%s\t%d\t%d\n",
		(*rooms)->index, (*rooms)->data.name, (*rooms)->data.x, (*rooms)->data.y);
		(*rooms) = (*rooms)->next;
	}
}

int		main(int argc, char **argv)
{
	t_rooms		*rooms;
	t_ants		*ants;

	ants = (t_ants*)ft_memalloc(sizeof(t_ants));
	read_input(&rooms, &ants);
	print_stuff(&rooms, &ants); //temporary
	return (FALSE);
}
