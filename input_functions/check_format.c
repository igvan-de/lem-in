/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_format.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:16:29 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/10 10:43:16 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


/*
** Checks for whitespaces in front of line
*/
void	no_whitespaces(char *line)
{
	if (line[0] == ' ' || line[0] == '\t' || line[0] == '\n' ||
		line[0] == '\v' || line[0] == '\f' || line[0] == '\r')
	{
		ft_putendl("Error! Whitespaces where there shouldn't be any");
		exit(-1);
	}
}

/*
** Ignores all commands "#" and checks if they are start or end
*/
bool	check_if_command(char *line, t_data **data)
{
	int i;

	i = 0;
	while (line && line[i])
		i++;
	if (i != 0 && line[0] == '#')
	{
		if (i >= 1 && line[1] == '#')
			is_start_or_end(line, data);
		return (true);
	}
	return (false);
}

/*
** Makes sure rooms are formatted correctly
*/
bool	check_format_room(char *line, t_data **data)
{
	int i;
	int space_count;

	i = 0;
	space_count = 1;
	no_whitespaces(line);
	if (check_if_command(line, data) == true)
		return (true);
	if (!line[i])
	{
		ft_putendl("Error! Empty line");
		exit(-1);
	}
	while (line[i] && line[i] != ' ')
		i++;
	if (line[0] == 'L')
	{
		ft_putendl("Error! Room name can't start with 'L'");
		exit(-1);
	}
	i++;
	if (space_counter(line, i, space_count) == true)
		return (true);
	else
		return (false);
}

/*
** Makes sure links are formatted correctly
*/
bool	check_format_link(char *line, t_input **input)
{
	char	**a_b;
	int		i;
	int		dash_count;

	i = 0;
	dash_count = 0;
	no_whitespaces(line);
	if (line && line[0] == '#')
		return (true);
	a_b = lem_split(line, input);
	if (compare_with_rooms(a_b, input) == false)
	{
		ft_putendl("Error! One or more of the links \
		points to an unexisting room");
		exit(-1);
	}
	ft_strarrdel(&a_b);
	if (dash_counter(line, i, dash_count) == true)
		return (true);
	else
	{
		ft_putendl("Error! One or more of the \
		links are not formatted correctly");
		exit(-1);
	}
}
