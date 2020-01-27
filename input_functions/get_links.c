/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_links.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/27 13:06:02 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This function reads the rest of a given file and sets all linking room in a linked list*/
static void		get_rest_of_links(t_input **rooms,
t_rooms **table, char *line, size_t size, char **a_b)
{
	while (get_next_line(STDIN_FILENO, &line) > 0 &&
	check_format_link(line, rooms) == true)
	{
		if (line && line[0] == '#')
		{
			free(line);
			continue ;
		}
		if (ft_strequ(a_b[A], a_b[B]) == true)
		{
			ft_putendl("Error! A room can't link to itself"); /*Error message to be determined*/
			exit(-1);
		}
		if (a_b != NULL)
			ft_strarrdel(&a_b);
		a_b = lem_split(line, rooms);
		set_links(table, size, a_b[A], a_b[B]); /*sets link A-B*/
		set_links(table, size, a_b[B], a_b[A]); /*sets link B-A*/
		ft_putendl(line);
		free(line);
	}
	ft_strarrdel(&a_b);
}

/*This function searches and give links to rooms
continues to check the format and give the links to room*/
void			get_links(t_input **rooms, t_rooms **table,
char *line, size_t size)
{ //Right now a room isn't allowed to link to itself, not sure if that's what we want
	char	**a_b;

	a_b = lem_split(line, rooms);
	if (check_format_link(line, rooms) == true &&
	ft_strequ(a_b[A], a_b[B]) == false)
	{
		if (a_b != NULL)
			ft_strarrdel(&a_b);
		a_b = lem_split(line, rooms);
		set_links(table, size, a_b[A], a_b[B]); /*sets link A-B*/
		set_links(table, size, a_b[B], a_b[A]); /*sets link B-A*/
	}
	else
	{
		ft_putendl("Error! The input is formatted incorrectly"); /*Error message to be determined*/
		exit(-1);
	}
	ft_putendl(line);
	get_rest_of_links(rooms, table, line, size, a_b);
	ft_putendl("");
	free(line);
}
