/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ants.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 13:43:21 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/15 15:03:57 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Checks for errors while reading given file
*/

void		error_check(int ret)
{
	if (ret < 0)
	{
		ft_putendl("Error! Something went wrong when trying to read the file");
		exit(-1);
	}
	if (ret == 0)
	{
		ft_putendl("Error! No file given to read");
		exit(-1);
	}
}

/*
** Iterates through line to check if given value for amount of ants is a digit
** If given ant value is negative, then ft_isdigit doenst recognize it is a number
*/

static int	ants_value_check(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == false)
		{
			ft_putendl("Error! Number of ants must be a (positive) number");
			exit(-1);
		}
		i++;
	}
	return (i);
}

/*
** Check every value in array to see if it will give max_int value
*/

static void	check_max_int(char *line)
{
	if (line[0] > '2')
		max_int_error();
	else if (line[1] > '1')
		max_int_error();
	else if (line[2] > '4')
		max_int_error();
	else if (line[3] > '7')
		max_int_error();
	else if (line[4] > '4')
		max_int_error();
	else if (line[5] > '8')
		max_int_error();
	else if (line[6] > '3')
		max_int_error();
	else if (line[7] > '6')
		max_int_error();
	else if (line[8] > '4')
		max_int_error();
	else if (line[9] > '7')
		max_int_error();
}

/*
** Finds amount of ants
*/

void		get_ants(t_data **ants, t_save_map *map)
{
	int i;

	while (map)
	{
		if (map->line[0] != '#')
			break ;
		map = map->next;
	}
	no_whitespaces(map->line);
	i = ants_value_check(map->line);
	if (i > 10)
		max_int_error();
	else if (i == 10 && map->line[0] != '1')
		check_max_int(map->line);
	(*ants)->amount_ants_start = ft_atoi(map->line);
}
