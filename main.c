/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/05 20:55:36 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include <fcntl.h>

static t_save_map	*new_line(char *line)
{
	t_save_map *new;

	if (line == NULL)
		return (NULL);
	new = (t_save_map*)ft_memalloc(sizeof(t_save_map));
	new->line = ft_strdup(line);
	return (new);
}

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

/*In this function we read from the standard input to collect the given data*/
static void			save_map(t_save_map **map)
{
	char			*line;
	int				ret;

	ret = get_next_line(STDIN_FILENO, &line);
	error_check(ret);
	add_new_line(map, new_line(line));
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		add_new_line(map, new_line(line));
		free(line);
	}
}

static int			read_input(t_save_map *map, t_input **input, t_data **data)
{
	size_t size;

	size = 0;
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
			size++;
		}
		map = map->next;
	}
	return (size);
}

/*This function is the brain of our program. It reads, saves, and processes all the data.
From here we continue to all our other functions.*/
// int	main(void)
int					main(int argc, char **argv)
{
	// }
	int fd;

	if (argc != 2)
	{
		printf("Please provide a test file!\n");
		return (false);
	}
	close(STDIN_FILENO);
	fd = open(argv[1], O_RDONLY);
	if (fd != STDIN_FILENO)
	{
		printf("fileno went wrong! Just run again.\n");
		return (false);
	}
	t_rooms			**rooms;
	t_input			*input;
	t_data			*data;
	size_t			size;
	t_save_map		*map;

	data = (t_data*)ft_memalloc(sizeof(t_data));
	input = NULL;
	map = NULL;
	save_map(&map);
	get_ants(&data, map);
	size = read_input(map, &input, &data);
	rooms = (t_rooms**)ft_memalloc(sizeof(t_rooms*) * size);
	hash_table(rooms, input, &data, size);
	get_links(&input, rooms, map, size, data);
	print_map(map);
	create_paths_and_send_ants(rooms, data, size);
	free(data);
	free_input(&input);
	return (0);
}

/* add this in main to use lldb debugger!
// {
*/
