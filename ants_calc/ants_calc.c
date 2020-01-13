/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ants_calc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/10 19:07:31 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

/*
** sends ants through the rooms
*/
void		send_ants(t_data **data, t_path_set *paths)
{
	int			start_ants;

	/*
	** ant_id starts on 1, the first ant that leaves start will be ant 1
	** then ant_id++ so the next ant that leaves start will be ant 2 etc.
	*/
	(*data)->ant_id = 1;
	/*
	** saving amount of starting ants to compare with ending ants
	** because we count down the amount of starting ants in the struct
	** as they go on their journey to the end so we know when we can
	** stop sending new ants from start
	*/
	start_ants = (*data)->starting_ants;
	/*
	** while loop isn't finished until amount of finishing ants is the same as starting
	*/
	while ((*data)->finishing_ants != start_ants)
	{
		print_paths(paths); //temporary
		if ((*data)->starting_ants != 0)
		{
			/*
			** send ant through fastest path
			**
			** while leftover ants are more than difference between next
			** fastest path and fastest path send next ant through next fastest path
			*/
			(*data)->starting_ants--;
			(*data)->ant_id++;
		}
		return ;
	}
}

/*
** calculates and returns how many ants we can get through in turns
*/
static int	how_many_ants(t_path *paths, int turns)
{
	int ants;
	int	calc;

	ants = 0;
	while (paths)
	{
		calc = turns - paths->path_size + 1;
		if (calc > 0)
			ants = ants + calc;
		paths = paths->next;
	}
	return (ants);
}

/*
** predicts and returns amount of turns needed to send ants through with current paths
*/
int			calc_turn_amount(t_data *data, t_path *paths)
{
	int		ants;
	int		turns;

	ants = 0;
	turns = 1;
	while (ants < data->amount_ants_start)
	{
		ants = how_many_ants(paths, turns);
		turns++;
	}
	return (turns);
}
