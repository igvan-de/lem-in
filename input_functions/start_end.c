/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_end.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:29:10 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/24 16:43:35 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This function checks the format of how start and end are given as input*/
static int	strict_start_end_checker(char *line) /*check all start and end variables*/
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

/*This function check if given line (input) is start or end and sets data->found_end ro data->found_start on*/
void		is_start_or_end(char *line, t_data **data) /*check if command is start or end*/
{
	while (*line == '#')
		line++;
	if (strict_start_end_checker(line) == 2)
	{
		/*changed the values 0, 1,2 to NOT_FOUND, FOUND and EXISTING
		 ask Yonne if this is ok for our code*/
		if ((*data)->found_end == NOT_FOUND)
			(*data)->found_end = FOUND;
		else if ((*data)->found_end == EXISTING)
		{
			ft_putendl("Error! There can't be more than 1 end room\n"); /*Error message to be determined*/
			exit(-1);
		}
	}
	else if (strict_start_end_checker(line) == 1)
	{
		if ((*data)->found_start == NOT_FOUND)
			(*data)->found_start = FOUND;
		else if ((*data)->found_start == EXISTING)
		{
			ft_putendl("Error! There can't be more than 1 start room\n"); /*Error message to be determined*/
			exit(-1);
		}
	}
}
