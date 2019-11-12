/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:32:20 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/12 17:29:47 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		add_node(t_rooms **node, t_rooms *new)
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
		prob = prob->next;
	prob->next = new;
}

static t_rooms	*new_node(char *line, t_ants **ants)
{
	t_rooms	*new_node;
	char	**name_x_y;

	name_x_y = ft_strsplit(line, ' ');
	new_node = (t_rooms*)ft_memalloc(sizeof(t_rooms));
	if (new_node == NULL)
		return (NULL);
	if ((*ants)->found_start == 1)
	{
		new_node->start = 1;
		(*ants)->found_start = 2;
	}
	else if ((*ants)->found_end == 1)
	{
		new_node->end = 1;
		(*ants)->found_end = 2;
	}
	new_node->name = name_x_y[NAME];
	new_node->x = ft_atoi(name_x_y[X]);
	new_node->y = ft_atoi(name_x_y[Y]);
	new_node->next = NULL;
	return (new_node);
}

void			add_to_list(char *line, t_rooms **head, t_ants **ants)
{
	t_rooms	*new;

	new = new_node(line, ants);
	if (new == NULL)
		return ;
	if ((*head) == NULL)
		*head = new;
	else
		add_node(head, new);
}
