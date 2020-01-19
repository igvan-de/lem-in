/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_useless_rooms.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/17 16:34:51 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	count_links(t_links *probe)
{
	int links;

	links = 0;
	while (probe)
	{
		probe = probe->next;
		links++;
	}
	return (links);
}

void		delete_link(t_links **probe, t_rooms *table)
{
	t_links *tmp;
	t_links *prev;

	tmp = *probe;
	while (tmp != NULL)
	{
		if (ft_strcmp(table->name, tmp->room->name) == 0)
		{
			prev->next = tmp->next;
			free (tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void		delete_node(t_rooms *head)
{
	t_rooms *dunno;

	if (!head)
		return ;
	dunno = head;
	if (head->type != END && head->type != START &&
	count_links(dunno->links) == 1)
	{
		delete_link(&head->links->room->links, head);
		head->type = USELESS;
		dunno = head->links->room;
		while (head->links->room->type != END && head->links->room->type != START &&
		count_links(dunno->links) == 1)
		{
			dunno->type = USELESS;
			delete_link(&dunno->links->room->links, dunno);
			dunno = dunno->links->room;
		}
	}
	else if (head->type != END && head->type != START)
	{
		dunno = head;
		if (count_links(dunno->links) == 0)
			head->type = USELESS;
	}
}

void		remove_useless_rooms(t_rooms **table, size_t size)
{
	size_t	i;
	t_rooms *tmp;
	t_rooms *prev;

	i = 0;
	while (i < size)
	{
		tmp = table[i];
		while (tmp)
		{
			delete_node(tmp);
			prev = tmp;
			tmp = tmp->next;
		}
		i++;
	}
}
