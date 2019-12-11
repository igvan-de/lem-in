/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dinics.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 11:53:49 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/11 14:19:51 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_path_data	*get_start(t_ants *ants)
{
	t_path_data	*start;

	start = (t_path_data*)ft_memalloc(sizeof(t_path_data));
	start->room = ants->begin;
	return (start);
}

static void			add_to_path(t_path_data **path, t_path_data *new)
{
	t_path_data	*probe;

	probe = *path;
	if (probe == NULL || new == NULL)
		return ;
	while (probe->next != NULL)
		probe = probe->next;
	probe->next = new;
	probe->towards = new->room;
}

static t_path_data	*get_shortest_link(t_table *room, int shortest_distance, t_links *link)
{
	t_path_data	*new;

	new = (t_path_data*)ft_memalloc(sizeof(t_path_data));
	new->room = room;
	while (link != NULL)
	{
		if (link->to->distance < shortest_distance && link->to->path == FALSE)
		{
			shortest_distance = link->to->distance;
			new->room = link->to;
		}
		link = link->next;
	}
	return (new);
}

static void		create_path(t_path_data **path, t_path_data *new)
{
	t_table		*previous;
	t_links		*link;
	int			shortest_distance;

	shortest_distance = (*path)->room->distance;
	while (new->room->type != END)
	{
		previous = new->room;
		link = new->room->links;
		new = get_shortest_link(new->room, shortest_distance, link);
		new->room->path = TRUE; //need to change to amount of paths || want to put this in linked list of existing paths
		new->room->links->shift = ON; //to make sure it doenst go into the wrong directions later
		new->from = previous;
		add_to_path(path, new);
	}
}

void			find_path(t_path_data **path, t_path_set **data_set, t_ants **ants)
{
	t_path_data	*new;

	*path = get_start(*ants);
	new = *path;
	create_path(path, new);
	new = NULL;
	free(new);
	path_set(data_set, *path);
}
