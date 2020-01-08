/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_table.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:45:51 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/08 14:25:11 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This function create a new space for the new room needed to be added in hash_table
It also sets the type to, START, END or FREE.
Depends of the room the start or end is of given grid*/
static t_rooms	*new_room(t_input *rooms)
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

/*This function adds a new room to the table*/
static void		add_to_table(t_rooms **head, t_rooms *new)
{
	if (head == NULL)
		return ;
	new->next = *head;
	*head = new;
}

/*This function calculates were to place a room in our hash_table*/
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

/*This function creates a hash_table from all the given data,
the has_table contains all our rooms*/
void			hash_table(t_rooms **table, t_input *rooms,
t_data **data, size_t size)
{
	size_t			index;

	while (rooms != NULL)
	{
		index = hash_function((unsigned char*)rooms->name, size);
		if (table[index] == NULL)
			table[index] = new_table(rooms);
		else
			add_to_table(&table[index], new_room(rooms));
		if (table[index]->type == START)
			(*data)->start_room = table[index];
		if (table[index]->type == END)
			(*data)->end_room = table[index];
		rooms = rooms->next;
	}
}
