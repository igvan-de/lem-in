/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ants.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 13:43:21 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/19 15:41:35 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*this function checks for while opening and reading given file*/
static void	error_check(int ret)
{
	if (ret < 0)
	{
		ft_putendl("Error! Something went wrong when trying to read the file"); /*Error message to be determined*/
		exit(-1);
	}
	if (ret == 0)
	{
		ft_putendl("Error! No file given to read"); /*Error message to be determined*/
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
			ft_putendl("Error! Number of ants must be a number"); /*Error message to be determined*/
			exit(-1);
		}
		i++;
	}
}

/*This function finds amount of ants and saves it in data struct*/
void		get_ants(t_data **ants)//Ask Yonne to check if this is a better name!
{
	char			*line;
	int				i;
	int				ret;

	i = 0;
	line = NULL;
	while (true)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		error_check(ret);
		if (line[i] != '#')
			break ;
		free(line);
	}
	no_whitespaces(line);
	ants_value_check(line, i);
	(*ants)->amount_ants_start = ft_atoi(line);
	ft_putendl(line);
	free(line);
}
