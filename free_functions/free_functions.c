/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 17:08:54 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/22 17:49:38 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_queue(t_queue **queue)
{
	if ((*queue)->next != NULL)
		free_queue(&(*queue)->next);
	free(*queue);
	*queue = NULL;
}

void	free_input(t_input **input)
{
	free((*input)->name);
	if ((*input)->next != NULL)
		free_input(&(*input)->next);
	free(*input);
	*input = NULL;
}

void	free_set(t_path_set **path)
{
	if ((*path)->next != NULL)
		free_set(&(*path)->next);
	free(*path);
	*path = NULL;
}
