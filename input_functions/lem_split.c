/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_split.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/20 17:29:43 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This functions set a_b[A] to  the first given room(name)
and a_b[B] to second given room(name)*/
char		**ft_split(char *line, int n, int c)
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

/*This functions check the if the links of rooms to exist*/
int			compare_with_rooms(char **a_b, t_input **input)
{
	t_input	*find_room;
	int		s;

	s = 0;
	find_room = *input;
	while (find_room)
	{
		if (ft_strequ(a_b[A], find_room->name) == TRUE)
			s++;
		if (ft_strequ(a_b[B], find_room->name) == TRUE)
			s++;
		if (s == 2)
			return (TRUE);
		find_room = find_room->next;
	}
	return (FALSE);
}

/*This function splits the given line so that we can seperate the first given room
and the second given room*/
char		**lem_split(char *line, t_input **input)
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
			a_b = ft_split(line, i, (c - i - 1));
			if (compare_with_rooms(a_b, input) == TRUE)
				break ;
			else
				ft_free_stringarray(a_b);
		}
		i++;
	}
	if (a_b == NULL || compare_with_rooms(a_b, input) == FALSE)
	{
		ft_putendl("Error! Linking to an unexisting room"); /*Error message to be determined*/
		exit(-1);
	}
	return (a_b);
}
