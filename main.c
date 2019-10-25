/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/24 16:48:26 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	char 	*line;
	t_link	*node;

	node = (t_link*)ft_memalloc(sizeof(t_link));
	while (get_next_line(STDIN_FILENO ,&line) > 0)
	{
		//format_checker
	}
	return (FALSE);
}