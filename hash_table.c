/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_table.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:45:51 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/04 13:36:34 by igvan-de      ########   odam.nl         */
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

static void	addToList(t_rooms **table, t_rooms *new) //IS TO ADD TO HASHTABLE LIST!
{
	new->next = *table;
	*table = new;
}

int			create_size(size_t	size)
{
	char	*line;

	size = 0;
	while (get_next_line(STDIN_FILENO, &line) > 0 && check_format_room(line) == TRUE)
	{
		if (check_if_command(line) == FALSE)
			size++;
	}
	return (size);
}

size_t		hashFunction(unsigned char *str, size_t size)
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

void		hashTable(t_rooms **table, t_rooms *room, size_t index)
{
	if (table[index] == NULL)
		table[index] = room;
	else
		addToList(&table[index], room);
}

/*

t_room   *hastable[1000];

t_room->name hasfunc(name) : int

if (!hashtable[int])
	hashtable[int] = t_room;
else 
	hashtable[int] : add_to_linked_list

*/