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

/*This function finds amount of ants*/
void	get_ants(t_data **ants)//Ask Yonne to check if this is a better name!
{
	char			*line;
	int				i;
	int				ret;

	i = 0;
	line = NULL;
	while (TRUE)
	{
		ret = get_next_line(STDIN_FILENO, &line);
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
		if (line[i] != '#')
			break ;
		free(line);
	}
	no_whitespaces(line);
	while (line[i])
	{
		if (ft_isdigit(line[i]) == FALSE)
		{
			ft_putendl("Error! Number of ants must be a number"); /*Error message to be determined*/
			exit(-1);
		}
		i++;
	}
	(*ants)->amount_ants_start = ft_atoi(line);
	free(line);
}


// void	move_ants(t_data **ants, t_path_set *data_set)
// {
// 	printf("ants = %d\n", (*ants)->start);
// 	printf("room = %s\n", data_set->path->rooms->room->name);
// 	while ((*ants)->end == 0)
// 	{

// 	}
// }
