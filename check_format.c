/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_format.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/30 15:26:36 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		no_whitespaces(char *line) //checking for whitespaces in front of line
{
	if (line[0] == ' ' || line[0] == '\t' || line[0] == '\n' ||
	line[0] == '\v' || line[0] == '\f' || line[0] == '\r')
	{
		ft_putendl("error"); //Error message to be determined
		exit(0);
	}
}

int				check_if_command(char *line) //ignoring all commands
{
	if (line[0] == '#')
	{
		if (line[1] == '#')
		{
			if (line[2] != '#') //make sure no segfault
				return (TRUE);
		}
	}
	return (FALSE);
}

int				check_format_room(char *line) //making sure rooms are formatted correctly
{ //make sure all rooms have a unique name and coordinates
	int i;
	int space_count;

	i = 0;
	space_count = 1; //already counted first space because we skip it
	no_whitespaces(line);
	if (check_if_command(line) == TRUE)
		return (TRUE);
	while (line [i] && line[i] != ' ')
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
	else
		return (FALSE);
}

static int	is_room(char *line, t_rooms *rooms) //making sure links are excisting rooms
{
	char	**a_b;

	a_b = ft_strsplit(line, '-');
	while (rooms)
	{
		if (ft_strcmp(rooms->data.name, a_b[0]) == 0 ||
		ft_strcmp(rooms->data.name, a_b[1]) == 0)
			return (TRUE);
		rooms = rooms->next;
	}
	return (FALSE);
}

int				check_format_link(char *line, t_rooms *rooms) //makng sure links are formatted correctly
{
	int i;
	int dash_count;

	i = 0;
	dash_count = 0;
	no_whitespaces(line);
	if (is_room(line, rooms) == FALSE)
		return (FALSE);
	while (line[i])
	{
		if (line[i] == '-')
			dash_count++;
		i++;
	}
	if (dash_count == 1)
		return (TRUE);
	else
	{
		ft_putendl("error"); //Error message to be determined
		exit(0);
	}
}
