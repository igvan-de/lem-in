/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_table.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:45:51 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/12 15:04:00 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


static t_table		*new_table(char *name)
{
	t_table *table;

	table = (t_table*)ft_memalloc(sizeof(t_table));
	table->name = name;
	return (table);
}

static void			add_to_table(t_table **head, t_table *new)
{
	if (head == NULL)
		return ;
	new->next = *head;
	*head = new;
}

size_t		hash_function(unsigned char *str, size_t size)
{
	size_t			hash;
	int				c;
	int				i;

	hash = 5381;
	i = 0;
	while (str[i])
	{
		c = str[i];
		hash = ((hash << 5) + hash) + c;
		i++;
	}
	return (hash % size);
}

void				hash_table(t_table **table, t_rooms *rooms, size_t size)
{
	size_t			index;

	while (rooms != NULL)
	{
		index = hash_function((unsigned char*)rooms->name, size);
		if (table[index] == NULL)
			table[index] = new_table(rooms->name);
		else
			add_to_table(&table[index], new_table(rooms->name));
		rooms = rooms->next;
	}
}
