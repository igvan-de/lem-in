/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/17 16:27:20 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_rooms			*rooms;
	t_data			*data;

	data = (t_data*)ft_memalloc(sizeof(t_data));
	read_input(&rooms, &data);
	//free rooms?
	//algorithm(table);
	return (FALSE);
}
