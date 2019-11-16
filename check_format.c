/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_format.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/16 17:02:09 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		no_whitespaces(char *line) /*checking for whitespaces in front of line*/
{
	int i;

	i = 0;
	if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' ||
		line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
	{
		ft_putendl("error"); /*Error message to be determined*/
		exit(0);
	}
}

int				check_if_command(char *line, t_ants **ants) /*ignoring all commands "#" and checking if they're start or end*/
{
	if (line && line[0] == '#')
	{
		is_start_or_end(line, ants);
		return (TRUE);
	}
	return (FALSE);
}

int				check_format_room(char *line, t_ants **ants) /*making sure rooms are formatted correctly*/
{
	int i;
	int space_count;

	i = 0;
	space_count = 1; /*already counted first space because we skip it*/
	no_whitespaces(line);
	if (check_if_command(line, ants) == TRUE)
		return (TRUE);
	while (line[i] && line[i] != ' ')
		i++;
	i++;
	while (line[i] && space_count < 3)
	{
		if (line[i] == ' ')
			space_count++;
		else if (ft_isdigit(line[i]) == FALSE)
			return (FALSE);
		i++;
	}
	if (space_count == 2)
		return (TRUE);
	else /*No error if room is not formatted correctly. We don't want to exit because this function is supposed to return FALSE if it reaches the links*/
		return (FALSE);
}

int				check_format_link(char *line, t_rooms **rooms, t_table **table, size_t size) /*making sure links are formatted correctly*/
{ //check for duplicate links (or do we not care there's duplicates?) //we don't care
	int i;
	int dash_count;

	i = 0;
	dash_count = 0;
	no_whitespaces(line);
	if (line && line[0] == '#') /*skip commands*/
		return (TRUE);
	if (compare_with_rooms(lem_split(line, rooms), rooms) == FALSE)
	{
		ft_putendl("One or more of the links points to an unexisting room"); /*Error message to be determined*/
		exit(0);
	}
	while (line[i])
	{
		if (line[i] == '-')
			dash_count++;
		i++;
	}
	if (dash_count >= 1)
		return (TRUE);
	else
	{
		ft_putendl("One or more of the links are not formatted correctly"); /*Error message to be determined*/
		exit(0);
	}
}
