/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/01 19:39:28 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		get_ants(t_ants **ants)
{
	char 	*line;
	int		i;

	i = 0;
	if (get_next_line(STDIN_FILENO, &line) < 0)
	{
		ft_putendl("error"); //Error message to be determined
		exit(0);
	}
	while (line[i])
	{
		if (ft_isdigit(line[i]) == FALSE)
		{
			ft_putendl("error"); //Error message to be determined
			exit(0);
		}
		i++;
	}
	(*ants)->start = ft_atoi(line);
	(*ants)->finish = 0;
}

static void		get_rooms(t_room **rooms)
{
	char			*line;

	while (get_next_line(STDIN_FILENO, &line) < 0)// &&check_format_room(line) == TRUE)
	{
		printf("line = %s\n", line);
		if (check_if_command(line) == FALSE) //need to make check for exsting room
		{
			(*rooms)->name = line[NAME];
			(*rooms)->x = line[X];
			(*rooms)->y = line[Y];
			/* *rooms = newItem(line); which one do we prefer to use over here? */
		}
	}
}

void			read_input(t_hashTable **table, t_ants **ants)
{
	int		size;
	size_t	index;
	t_room	*room;


	room = (t_room*)ft_memalloc(sizeof(t_room));
	get_ants(ants);
	size = create_size(size);
	table = (t_room**)ft_memalloc(sizeof(t_room*) * size);
	get_rooms(&room);
	printf("str = %s\n", room->name);
	printf("ant = %d\n", (*ants)->start);
	index = hashFunction(room->name, size);
	hashTable(table, room, index);
}
