/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/28 16:44:44 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		get_ants(t_ants *ants)
{
	char 	*line;
	int		i;

	if (get_next_line(STDIN_FILENO ,&line) < 0)
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
	ants->start = ft_atoi(line);
	ants->finish = 0;
}

static void		get_rooms(t_rooms *rooms)
{
	char			*line;
	int				n;

	n = 0;
	while (get_next_line(STDIN_FILENO, &line) > 0 &&
	check_format_room(line) == TRUE)
	{
		new_node(line, n);
		set_data(line, rooms);
		n++;
	}
	temp->n_rooms = n;
}

// static void		get_links(t_rooms *rooms)
// {
// 	char			*line;
// 	int				n;
// 	t_temp_links 	*links;
// 	t_temp_pointers	*temp;

// 	n = 0;
// 	while (get_next_line(STDIN_FILENO, &line) > 0 &&
// 	check_format_link(line, rooms) == TRUE) //add exit if check_format_link returns false
// 	{
// 		set_temp_links(line);
// 		n++;
// 		links = links->next;
// 	}
// 	temp->n_links = n;
// }

void			read_input(t_rooms *rooms, t_ants *ants)
{
	get_ants(ants);
	get_rooms(rooms);
	//get_links(rooms);
}
