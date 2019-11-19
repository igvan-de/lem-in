/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_split.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/15 19:57:11 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		**ft_split(char *line, int n, int c)
{
	char	**a_b;
	int		i;

	i = 0;
	a_b = (char**)ft_memalloc(sizeof(char*) * 2);
	a_b[A] = (char *)ft_memalloc(sizeof(char) * (n + 1));
	a_b[B] = (char *)ft_memalloc(sizeof(char) * (c + 1));
	while(i < n)
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
	return (a_b);
}

int			compare_with_rooms(char **a_b, t_rooms **rooms)
{
	t_rooms	*find_room;
	int		s;

	s = 0;
	find_room = *rooms;
	while (find_room)
	{
		if (ft_strequ(a_b[A], find_room->name) == TRUE)
			s++;
		else if (ft_strequ(a_b[B], find_room->name) == TRUE)
			s++;
		if (s == 2)
			return (TRUE);
		find_room = find_room->next;
	}
	return (FALSE);
}

char		**lem_split(char *line, t_rooms **rooms)
{
	char	**a_b;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while(line[c])
		c++;
	while(line[i])
	{
		if (line[i] == '-' && i != 0)
		{
			a_b = ft_split(line, i, (c - i - 1));
			if (compare_with_rooms(a_b, rooms) == TRUE)
				break ;
		}
		i++;
	}
	if (compare_with_rooms(a_b, rooms) == FALSE)
	{
		ft_putendl("error");
		exit(0);
	}
	return (a_b);
}
