/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_table.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:45:51 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/04 16:52:54 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/* CHECK IF WE WANT TO USE THIS FUNCTION
t_room	*newItem(char *line)
{
	t_room	*new;

	new = (t_room*)ft_memalloc(sizeof(t_room));
	new->name = line[NAME];
	new->x = line[X];
	new->y = line[Y];
	return (new);
} 
===========================================*/

size_t		hash_function(unsigned char *str, size_t size)
{
	size_t			hash;
	int				c;
	int				i;

	hash = 5381;
	i = 0;
	while(str[i])
	{
		c = str[i];
		hash = ((hash << 5) + hash) + c;
		i++;
	}
	return (hash % size);
}

static t_table		*new_table(char *name)
{
	t_table *table;

	table = (t_table*)ft_memalloc(sizeof(t_table));
	table->name = name;
	return (table);
}

static void			add_to_table(t_table **head, t_table *new)
{
	if (!head)
		return ;
	new->next = *head;
	*head = new;
}

void		hash_table(t_table **table, t_rooms *rooms, size_t size)
{
	size_t			index;

	while (rooms != NULL)
	{
		index = hash_function(rooms->name, size);
		if (table[index] == NULL)
			table[index] = new_table(rooms->name);
		else
			add_to_table(&table[index], new_table(rooms->name));
		rooms = rooms->next;
	}
}

/*

t_room   *hastable[1000];

t_room->name hasfunc(name) : int

if (!hashtable[int])
	hashtable[int] = t_room;
else 
	hashtable[int] : add_to_linked_list

*/