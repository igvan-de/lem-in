/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_set.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:32:36 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/07 17:22:41 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*============remove===========*/

void	print_path_set(t_path_set *data_set)
{
	t_path_set	*probe;
	t_path_data	*tmp;

	probe = data_set;
	tmp = probe->path;
	while (probe != NULL)
	{
		while (tmp != NULL)
		{
			printf("data->set->path = %s\n", tmp->room->name);
			tmp = tmp->next;
		}
		probe = probe->next;
	}
}
/*=============================*/

static t_path_set	*new_path(t_path_data *path)
{
	t_path_set	*new_set;

	new_set = (t_path_set*)ft_memalloc(sizeof(t_path_set));
	new_set->path = path;
	return (new_set);
}

static void			add_to_set(t_path_set **data_set, t_path_set *new)
{
	if (data_set == NULL)
		return ;
	new->next = *data_set;
	*data_set = new;
}

void				path_set(t_path_set **data_set, t_path_data *path)
{
	printf("test\n");
	*data_set = new_path(path);
	add_to_set(data_set, new_path(path));
	// data_set->path_id = data_set->path_id + 1;
	// printf("data_set->path_id = %d\n", data_set->path_id);
	print_path_set(*data_set);
	printf("============\n");
}
