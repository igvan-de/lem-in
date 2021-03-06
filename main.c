/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/03/06 13:05:12 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Allocates and sets new line
*/

static t_save_map	*new_line(char *line)
{
	t_save_map	*new;

	new = (t_save_map*)ft_memalloc(sizeof(t_save_map));
	new->line = line;
	return (new);
}

/*
** Adds new line to the end of linked list
*/

static void			add_new_line(t_save_map **map, t_save_map *new_line)
{
	t_save_map	*probe;

	if (new_line == NULL)
		return ;
	if (*map == NULL)
	{
		*map = new_line;
		return ;
	}
	probe = *map;
	while (probe->next != NULL)
		probe = probe->next;
	probe->next = new_line;
}

/*
** Reads standard input to collect the given data
*/

static void			save_map(t_save_map **map)
{
	char		*line;
	int			ret;

	line = NULL;
	ret = get_next_line(STDIN_FILENO, &line);
	error_check(ret);
	add_new_line(map, new_line(line));
	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		add_new_line(map, new_line(line));
		line = NULL;
	}
}

/*
** Saves input to data struct
*/

static void			save_input(t_save_map *map, t_input **input, t_data **data)
{
	while (map && (map->line[0] == '#' ||
	check_if_ants(map->line) == true))
	{
		if (check_if_ants(map->line) == true)
		{
			map = map->next;
			break ;
		}
		map = map->next;
	}
	while (map && check_format_room(map->line, data) == true)
	{
		if (check_if_command(map->line, data) == false)
		{
			add_to_list(map->line, input, data);
			(*data)->size++;
		}
		map = map->next;
	}
}

/*
** The brain of our program. It reads, saves, and processes all the data
*/
int		main(void)
{
	t_rooms			**rooms;
	t_input			*input;
	t_data			*data;
	t_save_map		*map;

	data = (t_data*)ft_memalloc(sizeof(t_data));
	input = NULL;
	map = NULL;
	save_map(&map);
	get_ants(&data, map);
	save_input(map, &input, &data);
	input_check(data);
	rooms = (t_rooms**)ft_memalloc(sizeof(t_rooms*) * (data->size));
	hash_table(rooms, input, &data);
	get_links(&input, rooms, map, data);
	print_map(map);
	create_paths_and_send_ants(rooms, data);
	free(data);
	free_input(&input);
	return (0);
}
