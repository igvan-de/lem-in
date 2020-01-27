/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_links.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/13 16:18:40 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
void			get_links(t_input **rooms, t_rooms **table,
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