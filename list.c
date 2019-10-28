/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:32:20 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/28 15:49:23 by ygroenev      ########   odam.nl         */
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

t_rooms	*new_node(char *str, int x, int y, int index)
{
	t_rooms	*new_node;
	
	new_node = (t_rooms*)ft_memalloc(sizeof(t_rooms));
	// if (link == NULL)
	// 	new_node->links = NULL;
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	return (new_node);
}
