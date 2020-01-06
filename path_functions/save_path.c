/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 19:20:22 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/06 14:03:52 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_paths	*new_path(t_path_data *new)
{
	t_paths	*new_path;
	t_paths	*tmp;

	new_path = (t_paths*)ft_memalloc(sizeof(t_paths));
	new_path->rooms = new;
	tmp = new_path;
	// while (tmp->rooms->room != NULL)
	// {
	// 	printf("start = %s\n", tmp->rooms->room->name);
	// 	tmp->rooms->room = tmp->rooms->room->next;
	// }
	return (new_path);
}

static void			add_to_set(t_paths **founded_path, t_paths *new)
{
	t_paths	*probe;

	probe = *founded_path;
	if (new == NULL)
		return ;
	if (probe->rooms == NULL)
	{
		new->path_id = probe->path_id + 1;
		*founded_path = new;
		return ;
	}
	while (probe->next != NULL)
		probe = probe->next;
	probe->next = new;
	new->path_id = probe->path_id + 1;
}


void	save_path(t_paths **founded_paths, t_path_data *path)
{
	add_to_set(founded_paths, new_path(path));
}
