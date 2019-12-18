/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ants_calc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/18 16:12:46 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// MATHS WE MIGHT NEED!
// (turns to get ants through path x) = (path x distance) + (ants) - 1
// (amount of ants that can go through path in x turns) = (x turns) - (path distance) + 1

/*
** temporary print function for testing
*/
static void	print_paths(t_path_set *paths)
{
	while (paths)
	{
		printf("path %d: ", paths->path_id);
		while (paths->path)
		{
			printf("%s", paths->path->room->name);
			if (paths->path->next)
				printf(", ");
			paths->path = paths->path->next;
		}
		printf("\n");
		paths = paths->next;
	}
}

void		ants_calc(t_data **data, t_path_set *paths)
{
	int			start_ants;
	// int		one = 3; //temporary path 1 length for ant_farms/test_4
	// int		two = 4; //temporary path 2 length for ant_farms/test_4
	// int		path_amount = 2; //temporary path amount for ant_farms/test_4


	/*
	** ant_id starts on 1, the first ant that leaves start will be ant 1
	** then ant_id++ so the next ant that leaves start will be ant 2 etc.
	*/
	(*data)->ant_id = 1;
	/*
	** saving amount of starting ants because we count down the amount of
	** starting ants in the struct as they go on their journey to the end
	** so we know when we can stop sending new ants from start
	*/
	start_ants = (*data)->starting_ants;
	/*
	** while loop isn't finished until amount of finishing ants is the same as starting
	*/
	while ((*data)->finishing_ants != start_ants)
	{
		// print_paths(paths); //temporary

		(*data)->starting_ants--;
		(*data)->ant_id++;
		return ;
	}
}
