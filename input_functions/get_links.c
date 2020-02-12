/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_links.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/10 15:27:13 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Reads the rest of a given file and sets all linking rooms in a linked list
*/
static void	get_rest_of_links(t_input **rooms,
t_rooms **table, t_save_map *map, size_t size)
{
	char	**a_b;

	a_b = lem_split(map->line, rooms);
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
		set_links(table, size, a_b[A], a_b[B]);
		set_links(table, size, a_b[B], a_b[A]);
		map = map->next;
	}
	ft_strarrdel(&a_b);
}

/*
** Checks if line contains only digits
*/
bool		check_if_ants(char *line)
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

/*
** Iterates through the map to get to the links
*/
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

/*
** Searches and adds links to rooms
*/
void		get_links(t_input **rooms, t_rooms **table,
t_save_map *map, t_data *data)
{
	char	**a_b;
	map = get_to_links(map, data);
	if (map && map->line && check_format_link(map->line, rooms) == false)
		bad_input();
	else if (map && map->line)
		a_b = lem_split(map->line, rooms);
	if (map && map->line && check_format_link(map->line, rooms) == true &&
	ft_strequ(a_b[A], a_b[B]) == false)
	{
		if (a_b != NULL)
			ft_strarrdel(&a_b);
		a_b = lem_split(map->line, rooms);
		set_links(table, data->size, a_b[A], a_b[B]);
		set_links(table, data->size, a_b[B], a_b[A]);
	}
	else
		bad_input();
	if (map->next)
		get_rest_of_links(rooms, table, map->next, data->size);
}
