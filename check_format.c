/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_format.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:16:29 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/19 15:11:23 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			no_whitespaces(char *line) /*checking for whitespaces in front of line*/
{
	if (line[0] == ' ' || line[0] == '\t' || line[0] == '\n' ||
		line[0] == '\v' || line[0] == '\f' || line[0] == '\r')
	{
		ft_putendl("Error! Whitespaces where there shouldn't be any"); /*Error message to be determined*/
		exit(-1);
	}
}

int				check_if_command(char *line, t_ants **ants) /*ignoring all commands "#" and checking if they're start or end*/
{
	int i;

	i = 0;
	while (line && line[i])
		i++;
	if (i != 0 && line[0] == '#')
	{
		if (i >= 1 && line[1] == '#')
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
	if (!line[i])
	{
		ft_putendl("Error! Empty line"); /*Error message to be determined*/
		exit(-1);
	}
	while (line[i] && line[i] != ' ')
		i++;
	if (line[0] == 'L')
	{
		ft_putendl("Error! Room name can't start with 'L'"); /*Error message to be determined*/
		exit(-1);
	}
	i++;
	while (line[i] && space_count < 3)
	{
		if (line[i] == ' ')
			space_count++;
		else if (ft_isdigit(line[i]) == FALSE)
		{
			ft_putendl("Error! Room coordinates must be numbers"); /*Error message to be determined*/
			exit(-1);
		}
		i++;
	}
	if (space_count == 2)
		return (TRUE);
	else /*No error if room is not formatted correctly. We don't want to exit because this function is supposed to return FALSE if it reaches the links*/
		return (FALSE);
}

int				check_format_link(char *line, t_rooms **rooms) /*making sure links are formatted correctly*/
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
		ft_putendl("Error! One or more of the links points to an unexisting room"); /*Error message to be determined*/
		exit(-1);
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
		ft_putendl("Error! One or more of the links are not formatted correctly"); /*Error message to be determined*/
		exit(-1);
	}
}
