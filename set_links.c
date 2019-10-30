/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_links.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/30 15:39:06 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		set_links(t_rooms **rooms, char *line)
{
	printf("line[0] = %c\n", line[0]);
	// printf("line[2] = %c\n", line[2]);
	while (ft_strnequ(&line[0], (*rooms)->data.name, 0) == FALSE)
	{
		// printf("test\n");
		printf("name = %s\n", (*rooms)->data.name);
		if (ft_strnequ(&line[0], (*rooms)->data.name, 0) == TRUE)
			printf("name = %s\n", (*rooms)->data.name);
		*rooms = (*rooms)->next;
	}
}
