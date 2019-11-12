/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/12 13:39:34 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		get_ants(t_ants **ants)
{
	char			*line;
	int				i;

	i = 0;
	if (get_next_line(STDIN_FILENO, &line) < 0)
	{
		ft_putendl("error"); /*Error message to be determined*/
		exit(0);
	}
	while (line[i])
	{
		if (ft_isdigit(line[i]) == FALSE)
		{
			ft_putendl("error"); /*Error message to be determined*/
			exit(0);
		}
		i++;
	}
	(*ants)->start = ft_atoi(line);
	(*ants)->finish = 0;
}

static size_t	get_rooms(t_rooms **rooms, char **line)
{
	size_t			size;

	size = 0;
	while (get_next_line(STDIN_FILENO, line) > 0 &&
			check_format_room(*line) == TRUE)
	{
		if (check_if_command(*line) == FALSE)
		{
			add_to_list(*line, rooms);
			size++;
		}
	}
	return (size);
}

static void		get_links(t_rooms **rooms, t_table **table, char *line, size_t size)
{
	char			**a_b;
	t_links			*link;

	link = (t_links*)ft_memalloc(sizeof(t_links));
	if (check_format_link(line, table, size) == TRUE)
	{
		a_b = ft_strsplit(line, '-');
		set_links(table, size, a_b[A], a_b[B]);
	}
	while (get_next_line(STDIN_FILENO, &line) > 0)// && check_format_link(line, table, size) == TRUE)
	{
		printf("line = %s\n", line);
		if (check_format_link(line, table, size) == TRUE)
		{
			a_b = ft_strsplit(line, '-');
			printf("test\n");
			set_links(table, size, a_b[A], a_b[B]);
		}
	}
}

void			read_input(t_table **table, t_rooms **rooms, t_ants **ants)
{
	char			*line;
	size_t			size;

	get_ants(ants);
	size = get_rooms(rooms, &line);
	table = (t_table**)ft_memalloc(sizeof(t_table*) * size);
	hash_table(table, *rooms, size);
	get_links(rooms, table, line, size);
	print_hash(table, size);
}
