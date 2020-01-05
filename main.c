/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/05 18:15:04 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <fcntl.h> // remove!!

int		main(int argc, char **argv) // make back to void
{
	int fd;
	t_rooms			*rooms;
	t_ants			*ants;

	ants = (t_ants*)ft_memalloc(sizeof(t_ants));
	// remove from here
	if (argc != 2)
	{
		printf("Please provide a test file!\n");
		return (FALSE);
	}
	close(STDIN_FILENO);
	fd = open(argv[1], O_RDONLY);
	if (fd != STDIN_FILENO)
	{
		printf("fileno went wrong! Just run again.\n");
		return (FALSE);
	}
	// until here. Is for debugging
	read_input(&rooms, &ants);
	return (FALSE);
}
