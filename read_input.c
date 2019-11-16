/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/16 16:58:16 by ygroenev      ########   odam.nl         */
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

static size_t	get_rooms(t_rooms **rooms, char **line, t_ants **ants)
{
	size_t			size;
	int 			i;

	size = 0;
	while (get_next_line(STDIN_FILENO, line) > 0 &&
	check_format_room(*line, ants) == TRUE)
	{
		if (check_if_command(*line, ants) == FALSE)
		{
			add_to_list(*line, rooms, ants);
			size++;
		}
	}
	return (size);
}

static void		get_rest_of_links(t_rooms **rooms,
t_table **table, char *line, size_t size, char **a_b)
{
	while (get_next_line(STDIN_FILENO, &line) > 0 &&
	check_format_link(line, rooms, table, size) == TRUE)
	{
		if (line && line[0] == '#')
			continue ;
		if (ft_strequ(a_b[A], a_b[B]) == TRUE)
		{
			ft_putendl("The imput is formatted incorrectly"); /*Error message to be determined*/
			exit(0);
		}
		a_b = lem_split(line, rooms);
		set_links(table, size, a_b[A], a_b[B]); /*sets link A-B*/
		set_links(table, size, a_b[B], a_b[A]); /*sets link B-A*/
	}
}

static void		get_links(t_rooms **rooms, t_table **table,
char *line, size_t size)
{ //Right now a room isn't allowed to link to itself, not sure if that's what we want
	char			**a_b;

	if (check_format_link(line, rooms, table, size) == TRUE &&
	ft_strequ(a_b[A], a_b[B]) == FALSE)
	{
		a_b = lem_split(line, rooms);
		set_links(table, size, a_b[A], a_b[B]); /*sets link A-B*/
		set_links(table, size, a_b[B], a_b[A]); /*sets link B-A*/
	}
	else
	{
		ft_putendl("The imput is formatted incorrectly"); /*Error message to be determined*/
		exit(0);
	}
	get_rest_of_links(rooms, table, line, size, a_b);
}

void			read_input(t_table **table, t_rooms **rooms, t_ants **ants)
{
	char			*line;
	size_t			size;

	get_ants(ants);
	size = get_rooms(rooms, &line, ants);
	table = (t_table**)ft_memalloc(sizeof(t_table*) * size);
	hash_table(table, *rooms, size);
	get_links(rooms, table, line, size);
	//print_rooms(*rooms, ants);
	print_hash(table, size);
}
