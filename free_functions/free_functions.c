/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 17:08:54 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/22 21:07:12 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_queue(t_queue **queue)
{
	if ((*queue)->next != NULL)
		free_queue(&(*queue)->next);
	ft_memdel((void**)queue);
}

void	free_input(t_input **input)
{
	free((*input)->name);
	if ((*input)->next != NULL)
		free_input(&(*input)->next);
	ft_memdel((void**)input);
}

void	free_set(t_path_set **path)
{
	if ((*path)->next != NULL)
		free_set(&(*path)->next);
	ft_memdel((void**)path);
}

void	free_path(t_path **path)
{
	if (*path == NULL)
		return ;
	if ((*path)->next != NULL)
		free_path(&(*path)->next);
	ft_memdel((void**)path);
}

void	free_path_set(t_path_set **set)
{
	if (*set == NULL)
		return;
	if ((*set)->path != NULL)
		free_path(&(*set)->path);
	if ((*set)->next != NULL)
		free_path_set(&(*set)->next);
	ft_memdel((void**)set);
}

void free_links(t_links **links)
{
	if (*links == NULL)
		return ;
	if ((*links)->next != NULL)
		free_links(&(*links)->next);
	ft_memdel((void**)links);
}

void free_rooms(t_rooms **rooms)
{
	if (*rooms == NULL)
		return ;
	if ((*rooms)->links != NULL)
		free_links(&(*rooms)->links);
	if ((*rooms)->next != NULL)
		free_rooms(&(*rooms)->next);
	ft_memdel((void**)rooms);
}
