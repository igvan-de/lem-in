/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_useless_rooms.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/17 14:17:00 by ygroenev      ########   odam.nl         */
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

void		delete_link(t_links **probe, t_table *table)
{
	t_links *tmp;
	t_links *prev;

	tmp = *probe;
	while (tmp != NULL)
	{
		if (ft_strcmp(table->name, tmp->to->name) == 0)
		{
			prev->next = tmp->next;
			free (tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void		delete_node(t_table *head)
{
	t_table *dunno;

	if (!head)
		return ;
	dunno = head;
	if (head->type != END && head->type != START &&
	count_links(dunno->links) == 1)
	{
		delete_link(&head->links->to->links, head);
		head->type = USELESS;
		dunno = head->links->to;
		while (head->links->to->type != END && head->links->to->type != START &&
		count_links(dunno->links) == 1)
		{
			dunno->type = USELESS;
			delete_link(&dunno->links->to->links, dunno);
			dunno = dunno->links->to;
		}
	}
	else if (head->type != END && head->type != START)
	{
		dunno = head;
		if (count_links(dunno->links) == 0)
			head->type = USELESS;
	}
}

void		remove_useless_rooms(t_table **table, size_t size)
{
	size_t	i;
	t_table *tmp;
	t_table *prev;

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

