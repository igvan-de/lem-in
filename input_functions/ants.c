/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ants.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 13:43:21 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/05 20:05:00 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*this function checks for while opening and reading given file*/
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

/*this function iterates through line to check if given values are digits*/
static void	ants_value_check(char *line, int i)
{
	while (line[i])
	{
		if (ft_isdigit(line[i]) == false)
		{
			ft_putendl("Error! Number of ants must be a number");
			exit(-1);
		}
		i++;
	}
}

/*This function finds amount of ants and saves it in data struct*/
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
}
