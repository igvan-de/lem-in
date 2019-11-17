/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/17 16:06:30 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_rooms			*rooms;
	t_ants			*ants;

	ants = (t_ants*)ft_memalloc(sizeof(t_ants));
	read_input(&rooms, &ants);
	//algorithm(table);
	return (FALSE);
}
