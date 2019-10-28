/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:32:20 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/28 17:00:49 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_node(t_rooms **node, t_rooms *new)
{
	t_rooms *prob;

	if (new == NULL)
		return ;
	if (*node == NULL)
	{
		*node = new;
		return ;
	}
	prob = *node;
	while (prob->next != NULL)
	{
		prob = prob->next;
	}
	prob->next = new;
}

t_rooms	*new_node(char *line, int index)
{
	t_rooms	*new_node;
	char	**name_x_y;

	name_x_y = ft_strsplit(line, ' ');
	new_node = (t_rooms*)ft_memalloc(sizeof(t_rooms));
	if (new_node == NULL)
		return (NULL);
	new_node->data.name = name_x_y[NAME];
	new_node->data.x = ft_atoi(name_x_y[X]);
	new_node->data.y = ft_atoi(name_x_y[Y]);
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}
