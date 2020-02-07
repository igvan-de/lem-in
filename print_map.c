/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/07 15:21:24 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_map(t_save_map *map)
{
	t_save_map	*previous;

	while (map != NULL)
	{
		ft_putendl(map->line);
		previous = map;
		free(previous->line);
		free(previous);
		map = map->next;
	}
	ft_putendl("");
}
