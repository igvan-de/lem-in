/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/17 15:54:08 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_rooms			*rooms;
	t_ants			*ants;

	ants = (t_ants*)ft_memalloc(sizeof(t_ants));
	read_input(&rooms, &ants);
	//free rooms?
	//algorithm(table);
	ants_calc();
	return (FALSE);
} //empty line at end of file doesn't give error, do we care?
