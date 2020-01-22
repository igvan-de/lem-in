/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ants_calc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/22 16:01:13 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** recursively loops through the paths and pushes all leftover ants one room
*/
static void	push_leftovers(t_data **data, t_path *begin)
{
	if (!begin)
		return ;
	push_leftovers(data, begin->next);
	if (begin->room->type == END || begin->room->type == START || begin->room->ant_id == 0)
		return ;
	else if (begin->next != NULL)
	{
		begin->next->room->ant_id = begin->room->ant_id;
		ft_putchar('L');
		ft_putnbr(begin->next->room->ant_id);
		ft_putchar('-');
		ft_putstr(begin->next->room->name);
		if (begin->room->from->type != START &&
		begin->room->ant_id != 0 && begin->room->from->ant_id != 0)
			ft_putchar(' ');
		begin->room->ant_id = 0;
	}
}

/*
** recursively loops through the paths and pushes all ants one room
*/
static void	push_ants(t_data **data, t_path *begin)
{
	if (!begin)
		return ;
	push_ants(data, begin->next);
	if (begin->room->type == END || begin->room->ant_id == 0)
		return ;
	else if (begin->next != NULL)
	{
		begin->next->room->ant_id = begin->room->ant_id;/*segfault!*/
		ft_putchar('L');
		ft_putnbr(begin->next->room->ant_id);
		ft_putchar('-');
		ft_putstr(begin->next->room->name);
		if (begin->room->type == START && (begin->room->ant_id < (*data)->amount_ants_start))
			begin->room->ant_id++;
		else
		{
			begin->room->ant_id = 0;
			ft_putchar(' ');
		}
	}
}

/*
** sends ants through the rooms
*/
void		send_ants(t_data **data, t_path_set **begin, int current_turn)
{
	t_path_set	*paths;

	paths = *begin;
	while (paths)
	{
		if (paths->path_size <= ((*data)->turns - current_turn) + 1)
			push_ants(data, paths->path);
		else
		{
			push_leftovers(data, paths->path);
		}
		paths = paths->next;
		if (paths == NULL && current_turn <= (*data)->turns)
		{
			ft_putchar('\n');
			send_ants(data, begin, (current_turn + 1));
		}
		else if (current_turn <= (*data)->turns)
			ft_putchar(' ');
	}
}

/*
** calculates and returns how many ants we can get through in turns
*/
static int	how_many_ants(t_path_set *paths, int turns)
{
	int		ants;
	int		calc;

	ants = 0;
	while (paths != NULL)
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
int			calc_turn_amount(t_data *data, t_path_set *paths)
{
	int		ants;
	int		turns;

	ants = 0;
	turns = 0;
	while (ants < data->amount_ants_start)
	{
		turns++;
		ants = how_many_ants(paths, turns);
	}
	return (turns);
}
