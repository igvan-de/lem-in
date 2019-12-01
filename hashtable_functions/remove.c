/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 13:02:35 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/29 12:35:17 by igvan-de      ########   odam.nl         */
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

static int	link_compare(t_table *table, t_table *link)
{
	printf("table = %s\n", table->links->to->name);
	printf("link = %s\n", link->links->to->name);
	if (table == link)
		return (TRUE);
	else
		return (FALSE);
}

void		delete_link(t_table *table)
{
	t_links *tmp;
	t_links	*prev;

	tmp = table->links->to->links;
	prev = tmp;
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			printf("===============\n");
			printf("prev = %s\n", prev->to->name);
			if (link_compare(table, tmp->to) == TRUE)
			{
				printf("tmp = %s\n", tmp->to->name);
				tmp->to = NULL;
				printf("tmp = %p\n", tmp->to);
				free (tmp);
				prev->next->to = tmp->next->to;
				printf("prev->next = %s\n", prev->next->to->name);
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

t_table		*delete_node(t_table *head)
{
	t_table *probe;

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

void		remove_link(t_table **table, size_t size)
{
	size_t	i;
	t_table **probe;

	i = 0;
	probe = table;
	while (i < size)
	{
		probe[i] = delete_node(probe[i]);
		i++;
	}
}
