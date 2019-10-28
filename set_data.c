/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/28 14:04:31 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		set_data(char *line, t_rooms *rooms)
{
	char **name_x_y;

	name_x_y = ft_strsplit(line, ' ');
	rooms->data->name = name_x_y[0];
	rooms->data->x = atoi(name_x_y[1]);
	rooms->data->y = atoi(name_x_y[2]);
}
