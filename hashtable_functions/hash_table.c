/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_table.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:45:51 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/21 11:38:38 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This function create a new space for the new room needed to be added in hash_table
It also sets the type to, START, END or FREE.
Depends of the room the start or end is of given grid*/
static t_rooms	*new_room(t_input *room)
{
	t_rooms *new_room;

	new_room = (t_rooms*)ft_memalloc(sizeof(t_rooms));
	if (room->start == true)
		new_room->type = START;
	else if (room->end == true)
		new_room->type = END;
	else
		new_room->type = FREE;
	new_room->name = room->name;
	new_room->next = NULL;
	return (new_room);
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
the hash_table contains all our rooms*/
void			hash_table(t_rooms **table_rooms, t_input *input,
t_data **data, size_t size)
{
	size_t			index;

	while (input != NULL)
	{
		index = hash_function((unsigned char*)input->name, size);
		if (table_rooms[index] == NULL)
			table_rooms[index] = new_room(input);
		else
			add_to_table(&table_rooms[index], new_room(input));
		if (table_rooms[index]->type == START)
			(*data)->start_room = table_rooms[index];
		if (table_rooms[index]->type == END)
			(*data)->end_room = table_rooms[index];
		input = input->next;
	}
}
