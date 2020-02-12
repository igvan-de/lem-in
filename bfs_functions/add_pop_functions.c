/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_pop_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 16:12:04 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/10 10:33:58 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Adds a new room at the end of the existing queue
*/
void	add_to_queue(t_queue **queue, t_queue *new)
{
	t_queue	*probe;

	if (new == NULL)
		return ;
	if (*queue == NULL)
	{
		*queue = new;
		return ;
	}
	probe = *queue;
	while (probe->next != NULL)
		probe = probe->next;
	probe->next = new;
}

/*
** Pops the first room of the queue
*/
void	pop_out_queue(t_queue **queue)
{
	t_queue	*first_node;

	first_node = *queue;
	*queue = (*queue)->next;
	free(first_node);
	first_node = NULL;
}
