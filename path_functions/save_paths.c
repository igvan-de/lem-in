/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 18:06:52 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/09 20:09:12 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*this function creates new space in path_set
and saves the new finded path to the path_set*/
void	save_paths(t_path *path)
{
	t_path_set	*new_path;

	if (path == NULL)
		return ;
	new_path = (t_path_set*)ft_memalloc(sizeof(t_path_set));
	while (new_path != NULL)
		new_path = new_path->next;
	new_path->path = path;
	print_path_set(new_path);
}
