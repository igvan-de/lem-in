/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 18:06:52 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/11 13:13:55 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*this function creates new space for */
static t_path_set	*new_path(t_path *path)
{
	t_path_set	*new_path;

	new_path = (t_path_set*)ft_memalloc(sizeof(t_path_set));
	new_path->path = path;
	return (new_path);
}

/*this function places a new path ad the end of a path_set*/
static void			add_to_set(t_path_set **existing_path_set, t_path_set *new_path)
{
	t_path_set	*path_set;

	path_set = *existing_path_set;
	if (path_set == NULL)
	{
		*existing_path_set = new_path;
		return ;
	}
	while (path_set->next != NULL)
		path_set = path_set->next;
	path_set->next = new_path;
}

/*this function creates new space in path_set
and saves the new finded path to the path_set*/
void				save_paths(t_path_set **path_set, t_path *path)
{
	if (path == NULL)
		return ;
	add_to_set(path_set, new_path(path));
}
