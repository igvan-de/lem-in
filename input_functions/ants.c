/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ants.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 13:43:21 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/12 11:28:37 by igvan-de      ########   odam.nl         */
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
static void	ants_value_check(char *line, int i)
{
	while (line[i])
	{
		if (ft_isdigit(line[i]) == false)
		{
			ft_putendl("Error! Number of ants must be a (positive) number");
			exit(-1);
		}
		i++;
	}
}

/*
** Finds amount of ants
*/
void		get_ants(t_data **ants, t_save_map *map)
{
	int				i;

	i = 0;
	while (map)
	{
		if (map->line[i] != '#')
			break ;
		map = map->next;
	}
	no_whitespaces(map->line);
	ants_value_check(map->line, i);
	(*ants)->amount_ants_start = ft_atoi(map->line);
	if ((*ants)->amount_ants_start < 0)
	{
		ft_putendl("Integer is bigger then MAX_INT");
		exit(-1);
	}
}
