/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ants.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 13:43:21 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/05 16:20:41 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_ants(t_ants **ants)
{
	char			*line;
	int				i;

	i = 0;
	if (get_next_line(STDIN_FILENO, &line) < 0)
	{
		ft_putendl("Error! Something went wrong when trying to read the file"); /*Error message to be determined*/
		exit(0);
	}
	no_whitespaces(line);
	while (line[i])
	{
		if (ft_isdigit(line[i]) == FALSE)
		{
			ft_putendl("Error! Number of ants must be a number"); /*Error message to be determined*/
			exit(0);
		}
		i++;
	}
	(*ants)->start = ft_atoi(line);
	(*ants)->finish = 0;
}


void	move_ants(t_ants **ants, t_path_set *data_set)
{
	printf("ants = %d\n", (*ants)->start);
	printf("room = %s\n", data_set->path->rooms->room->name);
	while ((*ants)->finish == 0)
	{

	}
}
