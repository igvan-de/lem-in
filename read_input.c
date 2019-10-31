/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/31 11:47:48 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		get_ants(t_ants **ants)
{
	char 	*line;
	int		i;

	i = 0;
	if (get_next_line(STDIN_FILENO, &line) < 0)
	{
		ft_putendl("error"); //Error message to be determined
		exit(0);
	}
	while (line[i])
	{
		if (ft_isdigit(line[i]) == FALSE)
		{
			ft_putendl("error"); //Error message to be determined
			exit(0);
		}
		i++;
	}
	(*ants)->start = ft_atoi(line);
	(*ants)->finish = 0;
}

static int		create_size(int	size)
{
	char	*line;

	size = 0;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (check_format_room(line) == TRUE)
			size++;
	}
	return (size);
}

void			read_input(t_hash_table **rooms, t_ants **ants)
{
	int size;

	size = create_size(size);
	rooms = create_hash_table(rooms, size);
	get_ants(ants);
}
