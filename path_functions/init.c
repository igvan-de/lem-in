/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 15:04:02 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/05 15:30:46 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init(t_amount **amount ,t_paths **founded_paths, t_path_set **data_set)
{
	*amount = (t_amount*)ft_memalloc(sizeof(t_amount));
	*founded_paths = (t_paths*)ft_memalloc(sizeof(t_paths));
	*data_set = (t_path_set*)ft_memalloc(sizeof(t_path_set));
}
