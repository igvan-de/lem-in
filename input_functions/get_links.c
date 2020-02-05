/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_links.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/05 20:55:25 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This function reads the rest of a given file and sets all linking room in a linked list*/
static void		get_rest_of_links(t_input **rooms,
t_rooms **table, t_save_map *map, size_t size, char **a_b)
{
	while (map && check_format_link(map->line, rooms) == true)
	{
		if (map->line && map->line[0] == '#')
		{
			map = map->next;
			continue ;
		}
		if (ft_strequ(a_b[A], a_b[B]) == true)
		{
			ft_putendl("Error! A room can't link to itself");
			exit(-1);
		}
		if (a_b != NULL)
			ft_strarrdel(&a_b);
		a_b = lem_split(map->line, rooms);
		set_links(table, size, a_b[A], a_b[B]); /*sets link A-B*/
		set_links(table, size, a_b[B], a_b[A]); /*sets link B-A*/
		map = map->next;
	}
	ft_strarrdel(&a_b);
}

int			check_if_ants(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

t_save_map	*get_to_links(t_save_map *map, t_data *data)
{
	while (map && (map->line[0] == '#' ||
	check_if_ants(map->line) == true))
		map = map->next;
	while (map && (map->line[0] == '#' ||
	check_format_room(map->line, &data) == true))
		map = map->next;
	return (map);
}
/*This function searches and give links to rooms
continues to check the format and give the links to room*/
void			get_links(t_input **rooms, t_rooms **table,
t_save_map *map, size_t size, t_data *data)
{
	char	**a_b;

	map = get_to_links(map, data);
	a_b = lem_split(map->line, rooms);
	if (check_format_link(map->line, rooms) == true &&
	ft_strequ(a_b[A], a_b[B]) == false)
	{
		if (a_b != NULL)
			ft_strarrdel(&a_b);
		a_b = lem_split(map->line, rooms);
		set_links(table, size, a_b[A], a_b[B]); /*sets link A-B*/
		set_links(table, size, a_b[B], a_b[A]); /*sets link B-A*/
	}
	else
	{
		ft_putendl("Error! The input is formatted incorrectly");
		exit(-1);
	}
	if (map->next)
		get_rest_of_links(rooms, table, map->next, size, a_b);
}
