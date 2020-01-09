/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:32:20 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/09 19:57:37 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*this functions add a new node at the back of the linked list*/
static void		add_node(t_input **node, t_input *new)
{
	t_input *probe;

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

/*this function creates a new node and set all its values*/
static t_input	*new_node(char *line, t_data **data)
{
	t_input	*new_node;
	char	**name_x_y;

	name_x_y = ft_strsplit(line, ' ');
	new_node = (t_input*)ft_memalloc(sizeof(t_input));
	if (new_node == NULL)
		return (NULL);
	if ((*data)->found_start == FOUND)
	{
		new_node->start = FOUND;
		(*data)->found_start = EXISTING;
	}
	else if ((*data)->found_end == FOUND)
	{
		new_node->end = FOUND;
		(*data)->found_end = EXISTING;
	}
	new_node->name = name_x_y[NAME];
	new_node->x = ft_atoi(name_x_y[X]);
	new_node->y = ft_atoi(name_x_y[Y]);
	new_node->next = NULL; /*unnecessary?*/
	return (new_node);
}

/*this function checks if there are any duplicates and returns error message if there's a duplicate founded*/
static void		check_for_duplicates(char *name, int x, int y, t_input *head)
{
	while (head != NULL)
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

/*this function adds a new node to the list*/
void			add_to_list(char *line, t_input **head, t_data **data)
{
	t_input	*new;

	new = new_node(line, data);
	check_for_duplicates(new->name, new->x, new->y, *head);
	if (new == NULL)
		return ;
	if (*head == NULL)
		*head = new;
	else
		add_node(head, new);
	// add_node(head, new_node(line, data));
}
