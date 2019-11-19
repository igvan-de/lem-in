/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:32:20 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/19 14:03:58 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		add_node(t_rooms **node, t_rooms *new)
{
	t_rooms *probe;

	if (new == NULL)
		return ;
	if (*node == NULL)
	{
		*node = new;
		return ;
	}
	probe = *node;
	while (probe->next != NULL)
		probe = probe->next;
	probe->next = new;
}

static t_rooms	*new_node(char *line, t_ants **ants)
{
	t_rooms	*new_node;
	char	**name_x_y;

	name_x_y = ft_strsplit(line, ' ');
	new_node = (t_rooms*)ft_memalloc(sizeof(t_rooms));
	if (new_node == NULL)
		return (NULL);
	if ((*ants)->found_start == FOUND)
	{
		new_node->start = FOUND;
		(*ants)->found_start = EXISTING;
	}
	else if ((*ants)->found_end == FOUND)
	{
		new_node->end = FOUND;
		(*ants)->found_end = EXISTING;
	}
	new_node->name = name_x_y[NAME];
	new_node->x = ft_atoi(name_x_y[X]);
	new_node->y = ft_atoi(name_x_y[Y]);
	new_node->next = NULL; /*unnecessary?*/
	return (new_node);
}

static void		check_for_duplicates(char *name, int x, int y, t_rooms *head)
{
	while (head->next != NULL)
	{
		if (ft_strequ(name, head->name) == TRUE)
		{
			ft_putendl("Error! Duplicate room names"); /*Error message to be determined*/
			exit(0);
		}
		if (head->x == x && head->y == y)
		{
			ft_putendl("Error! Duplicate coordinates"); /*Error message to be determined*/
			exit(0);
		}
		head = head->next;
	}
}

void			add_to_list(char *line, t_rooms **head, t_ants **ants)
{
	t_rooms	*new;

	new = new_node(line, ants);
	check_for_duplicates(new->name, new->x, new->y, *head);
	if (new == NULL)
		return ;
	if ((*head)->name == NULL)
		*head = new;
	else
		add_node(head, new);
}