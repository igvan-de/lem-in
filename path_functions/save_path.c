/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 19:20:22 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/05 21:05:25 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_paths	*new_path(t_path_data *new)
{
	t_paths	*new_path;

	new_path = (t_paths*)ft_memalloc(sizeof(t_paths));
	new_path->rooms = new;
	printf("new_path = %s\n", new_path->rooms->room->name);
	return (new_path);
}

static void			add_to_set(t_paths **founded_path, t_paths *new)
{
	t_paths	*probe;

	probe = *founded_path;
	if (new == NULL)
		return ;
	if (probe == NULL)
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
