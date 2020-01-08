/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_end.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:29:10 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/08 12:48:29 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		strict_start_end_checker(char *line) /*check all start and end variables*/
{
	int i;

	i = 0;
	while (line[i])
		i++;
	if (line && i == 5 && (line[0] == 's' || line[0] == 'S')
	&& (line[1] == 't' || line[1] == 'T')
	&& (line[2] == 'a' || line[2] == 'A')
	&& (line[3] == 'r' || line[3] == 'R')
	&& (line[4] == 't' || line[4] == 'T'))
		return (1);
	else if (line && i == 3 && (line[0] == 'e' || line[0] == 'E')
	&& (line[1] == 'n' || line[1] == 'N')
	&& (line[2] == 'd' || line[2] == 'D'))
		return (2);
	return (0);
}

void			is_start_or_end(char *line, t_data **ants) /*check if command is start or end*/
{
	while (*line == '#')
		line++;
	if (strict_start_end_checker(line) == 2)
	{
		if ((*ants)->found_end == 0)
			(*ants)->found_end = 1;
		else if ((*ants)->found_end == 2)
		{
			ft_putendl("Error! There can't be more than 1 end room\n"); /*Error message to be determined*/
			exit(0);
		}
	}
	else if (strict_start_end_checker(line) == 1)
	{
		if ((*ants)->found_start == 0)
			(*ants)->found_start = 1;
		else if ((*ants)->found_start == 2)
		{
			ft_putendl("Error! There can't be more than 1 start room\n"); /*Error message to be determined*/
			exit(0);
		}
	}
}
