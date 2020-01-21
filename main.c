/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/21 21:23:29 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <fcntl.h> // remove!!

/*In this function we read from the standard input to collect the given data*/
size_t			get_input(t_input **input, char **line, t_data **data)
{
	size_t			size;

	size = 0;
	while (get_next_line(STDIN_FILENO, line) > 0  &&
	check_format_room(*line, data) == TRUE)
	{
		if (check_if_command(*line, data) == FALSE)
		{
			add_to_list(*line, input, data);
			size++;
		}
		free(*line);
	}
	return (size);
}

/*This function is the brain of our program. It reads, saves, and processes all the data.
From here we continue to all our other functions.*/
int		main(int argc, char **argv) // make back to void
{
	int fd; //remove!!
	t_rooms			**rooms;
	t_input			*input;
	t_data			*data;
	size_t			size;
	char			*line;

	// remove from here
	if (argc != 2)
	{
		printf("Please provide a test file!\n");
		return (FALSE);
	}
	close(STDIN_FILENO);
	fd = open(argv[1], O_RDONLY);
	if (fd != STDIN_FILENO)
	{
		printf("fileno went wrong! Just run again.\n");
		return (FALSE);
	}
	// until here. Is for debugging
	data = (t_data*)ft_memalloc(sizeof(t_data));
	input = NULL;
	get_ants(&data);
	size = get_input(&input, &line, &data);
	rooms = (t_rooms**)ft_memalloc(sizeof(t_rooms*) * size);
	hash_table(rooms, input, &data, size);
	get_links(&input, rooms, line, size);
	// remove_useless_rooms(rooms, size); /*doens't really work*/
	create_paths_and_send_ants(rooms, data, size);
	// while(TRUE)
	// 	;
	return (0);
}
