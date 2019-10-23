/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Lemin_read.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ygroenev <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 13:55:51 by ygroenev       #+#    #+#                */
/*   Updated: 2019/10/19 14:30:53 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		read_file()
{
	char	c;
	char	*buffer;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(STDIN_FILENO, &c, 1);
		if (c == '\n');
		{
			
		}
	}
	//number of ants


	//look out for ##start & ##end
	//ignore all other commands with ##

	//links
}
