/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_set.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:32:36 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/05 19:25:02 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_path_set	*new_set(t_paths *founded_paths)
{
	t_path_set	*new_set;

	new_set = (t_path_set*)ft_memalloc(sizeof(t_path_set));
	new_set->path = founded_paths;
	return (new_set);
}

static void			add_to_set(t_path_set **data_set, t_path_set *new)
{
	t_path_set	*probe;

	probe = *data_set;
	if (new == NULL)
		return ;
	if (probe->path == NULL)
	{
		new->set_id = probe->set_id + 1;
		*data_set = new;
		return ;
	}
	while (probe->next != NULL)
		probe = probe->next;
	probe->next = new;
	new->set_id = probe->set_id + 1;
}

void				path_set(t_path_set **data_set, t_paths *founded_paths)
{
	add_to_set(data_set, new_set(founded_paths));
	print_path_set(*data_set); //remove!
}
