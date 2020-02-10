/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_split.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/10 10:44:32 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Splits the room names of a link
*/
char	**ft_split(char *line, int n, int c)
{
	char	**a_b;
	int		i;

	i = 0;
	a_b = (char**)ft_memalloc(sizeof(char*) * 3);
	a_b[A] = (char*)ft_memalloc(sizeof(char) * (n + 1));
	a_b[B] = (char*)ft_memalloc(sizeof(char) * (c + 1));
	while (i < n)
	{
		a_b[A][i] = line[i];
		i++;
	}
	a_b[A][i] = '\0';
	i++;
	n = 0;
	while (line[i])
	{
		a_b[B][n] = line[i];
		n++;
		i++;
	}
	a_b[B][n] = '\0';
	a_b[2] = NULL;
	return (a_b);
}

/*
** Checks if the rooms in a link exist
*/
int		compare_with_rooms(char **a_b, t_input **input)
{
	t_input	*find_room;
	int		s;

	s = 0;
	find_room = *input;
	while (find_room != NULL)
	{
		if (ft_strequ(a_b[A], find_room->name) == true)
			s++;
		if (ft_strequ(a_b[B], find_room->name) == true)
			s++;
		if (s == 2)
			return (true);
		find_room = find_room->next;
	}
	return (false);
}

void	print_error(void)
{
	ft_putendl("Error! Linking to an unexisting room");
	exit(-1);
}

/*
** Splits the room names in a link and checks if they exist
*/
char	**lem_split(char *line, t_input **input)
{
	char	**a_b;
	int		i;
	int		c;

	i = 0;
	c = 0;
	a_b = NULL;
	while (line[c])
		c++;
	while (line[i])
	{
		if (line[i] == '-' && i != 0)
		{
			if (a_b != NULL)
				ft_strarrdel(&a_b);
			a_b = ft_split(line, i, (c - i - 1));
			if (compare_with_rooms(a_b, input) == true)
				break ;
		}
		i++;
	}
	if (a_b == NULL || compare_with_rooms(a_b, input) == false)
		print_error();
	return (a_b);
}
