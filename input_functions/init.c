/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 13:08:04 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/16 14:00:11 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init(size_t size, t_table ***table, t_path_set **data_set,
t_path_data **path)
{
	*table = (t_table**)ft_memalloc(sizeof(t_table*) * size);
	*data_set = (t_path_set*)ft_memalloc(sizeof(t_path_set));
	*path = (t_path_data*)ft_memalloc(sizeof(t_path_data));
}
