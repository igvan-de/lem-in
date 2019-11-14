/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/14 12:55:30 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	t_table			**table;
	t_rooms			*rooms;
	t_ants			*ants;

	ants = (t_ants*)ft_memalloc(sizeof(t_ants));
	read_input(table, &rooms, &ants);
	//algorithm(table);
	return (FALSE);
}
