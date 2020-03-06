/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 11:04:18 by igvan-de       #+#    #+#                */
/*   Updated: 2020/03/06 13:05:46 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <fcntl.h>

/*
** This main is needed if you want to use LLD debugger for this program
** Need to close STDIN_FILENO so we create space to place given file to read from STDIN_FILENO
*/

int		debug_main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putendl("Please provide a test file!");
		return (false);
	}
	close(STDIN_FILENO);
	fd = open(argv[1], O_RDONLY);
	if (fd != STDIN_FILENO)
	{
		ft_putendl("fileno went wrong! Just run again.");
		return (false);
	}
	return (0);
}
