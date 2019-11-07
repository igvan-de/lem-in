/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_links.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:29:10 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/07 17:37:02 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_links		*new_link(char *name)
{
	t_links	*link;

	link = (t_links*)ft_memalloc(sizeof(t_links));
	link->to = name;
	return (link);
}

static void			add_to_links(t_table **head, t_links *new)
{
	if ((*head)->links == NULL)
		return ;
	new->next = (*head)->links;
	(*head)->links = new;
}

void				set_links(t_table **table, size_t size, char *nameA, char *nameB)
{
	int				i;
	size_t			index;

	printf("nameA = %s\n", nameA);
	printf("nameB = %s\n", nameB);
	i = 0;
	index = hash_function((unsigned char*)nameA, size); //typecast a_b[A] to (char)a_b[A]!! Check if this is really needed
	if (table[index]->links == NULL)
	{
		while (i < size)
		{
			while (table[i] != NULL)
			{
				if (ft_strcmp(table[i]->name, nameA) == 0)
				{			
					table[index]->links = new_link(nameB);
					printf("table[%zu] = %s\t", index, table[index]->name);
					break ;
				}
				table[i] = table[i]->next;
				printf("test\n");
			}
			i++;
		}
		while (table[index]->links != NULL)
		{
			printf("table[%zu]->links->to = %s\n", index, table[index]->links->to);
			table[index]->links = table[index]->links->next;
		}
	}
	else
		add_to_links(table[index]->links, new_link(nameB));
	// table[index]->links = a_b[B];
	// table[index]->links->to = a_b[B];
	// table[index]->links = table[index]->links->next;
}