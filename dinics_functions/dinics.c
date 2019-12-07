/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dinics.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 11:53:49 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/07 17:12:51 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_path_data	*get_start(t_ants *ants)
{
	t_path_data *start;

	start = (t_path_data*)ft_memalloc(sizeof(t_path_data));
	start->room = ants->begin;
	return (start);
}

static void			add_to_path(t_path_data **path, t_path_data *new)
{
	//place add back!!
	new->next = *path;
	*path = new;
}

static t_path_data	*get_shortest_link(t_table *room, int shortest_distance, t_links *link)
{
	t_path_data *new;

	new = (t_path_data*)ft_memalloc(sizeof(t_path_data));
	new->room = room;
	while (link != NULL)
	{
		if (link->to->distance < shortest_distance && link->to->path_id == FALSE)
		{
			shortest_distance = link->to->distance;
			// new->towards = link->to;
			new->room = link->to;
		}
		link = link->next;
	}
	return (new);
}

void			find_path(t_path_set **data_set, t_ants **ants)
{
	t_path_data	*path;
	t_path_data	*new;
	t_table		*previous;
	t_links		*link;
	int			shortest_distance;

	path = get_start(*ants);
	new = path;
	shortest_distance = path->room->distance;
	previous = path->room;
	while (path->room->type != END)
	{
		previous = path->room;
		link = path->room->links;
		new = get_shortest_link(path->room, shortest_distance, link);
		new->room->path_id = TRUE; //need to change to amount of paths || want to put this in linked list of existing paths
		new->room->links->direction = TRUE; //make pointer to room the path is going to!
		new->from = previous;
		add_to_path(&path, new);
	}
	path_set(data_set, path);
}
