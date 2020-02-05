/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   counter_check.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 17:02:59 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/05 14:10:10 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*space_counter, counts the amount of spaces and return true if it's equal to two else it returns false*/
bool	space_counter(char *line, int i, int space_count)
{
	while (line[i] && space_count < 3)
	{
		if (line[i] == ' ')
			space_count++;
		i++;
	}
	if (space_count == 2)
		return (true);
	else
		return (false);
}

/*dash_counter returns true if there are more then one dashes on the given line, else it returns false*/
bool	dash_counter(char *line, int i, int dash_count)
{
	while (line[i])
	{
		if (line[i] == '-')
			dash_count++;
		i++;
	}
	if (dash_count >= 1)
		return (true);
	else
		return (false);
}
