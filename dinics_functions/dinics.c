/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dinics.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 11:53:49 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/05 18:37:08 by igvan-de      ########   odam.nl         */
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
	t_path_data *probe;

	probe = *path;
	// new->next = *path;
	// *path = new;
	printf("path->room = %s\n", (*path)->room->name);
	printf("new->room = %s\n", new->room->name);
	while (probe->next != NULL)
		probe = probe->next;
	probe->next = new;
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
			printf("tmp = %s\t pointer %p\n", room->name, new);
		}
		link = link->next;
	}
	return (new);
}

void			find_path(t_ants **ants)
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
		path->room->path_id = TRUE; //need to change to amount of paths || want to put this in linked list of existing paths
		path->room->links->direction = TRUE; //make pointer to room the path is going to!
		path->from = previous;
		add_to_path(&path, new);
	}
	while (path != NULL)
	{
		printf("path = %s\n", path->room->name);
		path = path->next;
	}
	// path_set(path);
}
