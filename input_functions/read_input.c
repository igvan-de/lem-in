/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/08 14:38:01 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*In this function we read from the standard input to collect the given data*/
static size_t	get_input(t_input **rooms, char **line, t_data **data)
{
	size_t			size;

	size = 0;
	while (get_next_line(STDIN_FILENO, line) > 0 &&
	check_format_room(*line, data) == TRUE)
	{
		if (check_if_command(*line, data) == FALSE)
		{
			add_to_list(*line, rooms, data);
			size++;
		}
	}
	return (size);
}

/*This function */
static void		get_rest_of_links(t_input **rooms,
t_rooms **table, char *line, size_t size, char **a_b)
{
	while (get_next_line(STDIN_FILENO, &line) > 0 &&
	check_format_link(line, rooms) == TRUE)
	{
		if (line && line[0] == '#')
			continue ;
		if (ft_strequ(a_b[A], a_b[B]) == TRUE)
		{
			ft_putendl("Error! A room can't link to itself"); /*Error message to be determined*/
			exit(0);
		}
		a_b = lem_split(line, rooms);
		set_links(table, size, a_b[A], a_b[B]); /*sets link A-B*/
		set_links(table, size, a_b[B], a_b[A]); /*sets link B-A*/
	}
}

/*This function searches and give links to rooms
continues to check the format and give the links to room*/
static void		get_links(t_input **rooms, t_rooms **table,
char *line, size_t size)
{ //Right now a room isn't allowed to link to itself, not sure if that's what we want
	char	**a_b;

	a_b = lem_split(line, rooms);
	if (check_format_link(line, rooms) == TRUE &&
	ft_strequ(a_b[A], a_b[B]) == FALSE)
	{
		a_b = lem_split(line, rooms);
		set_links(table, size, a_b[A], a_b[B]); /*sets link A-B*/
		set_links(table, size, a_b[B], a_b[A]); /*sets link B-A*/
	}
	else
	{
		ft_putendl("Error! The imput is formatted incorrectly"); /*Error message to be determined*/
		exit(0);
	}
	get_rest_of_links(rooms, table, line, size, a_b);
}


void			read_input(t_input **rooms, t_data **data)
{
	t_rooms			**table;
	size_t			size;
	char			*line;

	get_ants(data);
	size = get_input(rooms, &line, data);
	table = (t_rooms**)ft_memalloc(sizeof(t_rooms*) * size);
	hash_table(table, *rooms, data, size);
	get_links(rooms, table, line, size);
	/*
	1. BFS function to find quickest path
	2. Path function to create path (turn shift on or off in oppisite values as there are when probing over them)
	3. Save path
	4. Repeat step 1 and 2
	5. Before saving new paths, calculate if the newly finded paths are quicker to use for amount of ants
	6. If step 5 is prover that the new paths are quicker, save them
	*/
}

	// remove_link(table, size);
	// move_ants(ants, data_set);
	// print_hash(table, size);
	// print_input(*rooms, ants);
