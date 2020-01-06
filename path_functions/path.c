/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 15:03:44 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/06 17:41:29 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			set_path_amount(t_amount **amount, t_ants *ants)
{
	t_links		*tmp;
	int			a;
	int			b;

	a = 1;
	b = 1;
	tmp = ants->begin->links;
	while (tmp->next != NULL)
	{
		a++;
		tmp = tmp->next;
	}
	tmp = ants->end->links;
	while (tmp->next != NULL)
	{
		b++;
		tmp = tmp->next;
	}
	if (a >= b)
		(*amount)->max_path_amount = b;
	else
		(*amount)->max_path_amount = a;
}

static int			check_path_amount(t_amount *amount)
{
	if (amount->path_amount < amount->max_path_amount)
		return (TRUE);
	return (FALSE);
}

void				path(t_table **table, t_ants **ants, size_t size)
{
	t_amount		*amount;
	t_paths			*founded_paths;
	t_path_set		*data_set;

	init(&amount, &founded_paths, &data_set);
	set_path_amount(&amount, *ants);
	while (check_path_amount(amount) == TRUE)
	{
		/*Need to check if bfs function needs to be in while loop*/
		bfs(ants, table, size);
		search_paths(&founded_paths, ants);
		path_set(&data_set, founded_paths);
		/*Added the next two lines, to reset the values.
		Dont, want to take the previous paths in the new set.
		Want to find all possible path(s)*/
		founded_paths->rooms = NULL;
		data_set->path = NULL;
		/*====================================*/
		amount->path_amount += 1;
	}
}
