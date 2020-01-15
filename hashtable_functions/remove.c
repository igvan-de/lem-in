/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 13:02:35 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/13 16:30:34 by ygroenev      ########   odam.nl         */
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

static int	link_compare(t_rooms *room, t_rooms *link)
{
	if (room == link)
		return (TRUE);
	else
		return (FALSE);
}

void		delete_link(t_rooms *room)
{
	t_links *tmp;
	t_links	*prev;

	tmp = room->links->room->links;
	prev = tmp;
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			if (link_compare(room, tmp->room) == TRUE)
			{
				tmp->room = NULL;
				free (tmp);
				prev->next->room = tmp->next->room;
				return ;
			}
			// printf("room name %s\n", tmp->to->name);
			prev = tmp;
			tmp = tmp->next;
		}
	}
}
			// if (table->name == tmp->to->name)
			// {
			// 	printf("tmp = %s\n", tmp->to->name);
			// 	printf("tmp next = %p\n", tmp->next);
			// 	tmp2 = tmp->next;
			// 	free (tmp);
			// 	tmp = NULL;
			// 	tmp = tmp2;
			// 	return ;
			// }

t_rooms		*delete_node(t_rooms *head)
{
	t_rooms *probe;

	if (!head)
		return (NULL);
	probe = head;
	if (head->type != END && head->type != START &&
	count_links(probe->links) <= 1)
	{
		while (probe != NULL)
		{
			if (link_compare(head, probe) == TRUE)
			{
				delete_link(probe); // || delete_link(head);
				// head = probe; ??
				return (head);
			}
			probe = probe->next;
		}
	}
	head->next = delete_node(head->next);
	return (head);
}

void		remove_link(t_rooms **rooms, size_t size)
{
	size_t	i;
	t_rooms **probe;

	i = 0;
	probe = rooms;
	while (i < size)
	{
		probe[i] = delete_node(probe[i]);
		i++;
	}
}
