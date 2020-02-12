/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 15:06:52 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/12 11:33:47 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Checks if end_room has an path_id to check if there is an path created
*/
void	no_path(t_data *data)
{
	t_rooms	*end;

	end = data->end_room;
	if (end->path_id == 0)
	{
		ft_putendl("No path possible");
		exit(-1);
	}
}

/*
** Checks if the three most important values in data are given in map
*/
void	input_check(t_data *data)
{
	if (data->found_start == 0 || data->found_end == 0)
	{
		ft_putendl("Error! There's no start and/or end room");
		exit(-1);
	}
	else if (data->amount_ants_start == 0)
	{
		ft_putendl("Error! There are no ants");
		exit(-1);
	}
}

/*
** Checks if amount of ants isn't bigger then MAX_INT,
** if amount is bigger then MAX_INT amount_ants will be a negative number
*/
void	ants_amount_check(int amount_ants)
{
	if (amount_ants < 0)
	{
		ft_putendl("Integer is bigger then MAX_INT");
		exit(-1);
	}
}

void	bad_input(void)
{
	ft_putendl("Error! The input is formatted incorrectly");
	exit(-1);
}
