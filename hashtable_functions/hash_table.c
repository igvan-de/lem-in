/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_table.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:45:51 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/08 12:50:52 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_rooms	*new_table(t_input *rooms)
{
	t_rooms *table;

	table = (t_rooms*)ft_memalloc(sizeof(t_rooms));
	if (rooms->start == TRUE)
		table->type = START;
	else if (rooms->end == TRUE)
		table->type = END;
	else
		table->type = FREE;
	table->name = rooms->name;
	return (table);
}

static void		add_to_table(t_rooms **head, t_rooms *new)
{
	if (head == NULL)
		return ;
	new->next = *head;
	*head = new;
}

size_t			hash_function(unsigned char *str, size_t size)
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

void			hash_table(t_rooms **table, t_input *rooms,
t_data **ants, size_t size)
{
	size_t			index;

	while (rooms != NULL)
	{
		index = hash_function((unsigned char*)rooms->name, size);
		if (table[index] == NULL)
			table[index] = new_table(rooms);
		else
			add_to_table(&table[index], new_table(rooms));
		if (table[index]->type == START)
			(*ants)->start_room = table[index];
		if (table[index]->type == END)
			(*ants)->end = table[index];
		rooms = rooms->next;
	}
}
