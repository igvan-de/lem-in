/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_find_path.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 15:03:44 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/04 16:43:32 by igvan-de      ########   odam.nl         */
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

static t_path_data	*get_shortest_link(t_table *room, int shortest_distance, t_links *link)
{
	t_path_data	*new;

	new = (t_path_data*)ft_memalloc(sizeof(t_path_data));
	new->room = room;
	while (link != NULL)
	{
		if (link->to->distance < shortest_distance)
		{
			shortest_distance = link->to->distance;
			new->room = link->to;
			if (new->room->links->shift == ON)
				new->room->links->shift = OFF;
			else
				new->room->links->shift = ON;
		}
		link = link->next;
	}
	return (new);
}

static void			add_to_path(t_path_data **path, t_path_data *new)
{
	t_path_data	*probe;

	probe = *path;
	if (probe == NULL || new == NULL)
		return ;
	while (probe->next != NULL)
	{
		// printf("probe->next = %s\n", probe->next->room->name);
		probe = probe->next;
	}
	new->room->from = probe->room;
	probe->next = new;
	probe->room->path = TRUE; //check this!
	probe->towards = new->room;
	probe->room->towards = new->room;
}

static void		create_path(t_path_data **path, t_path_data *new)
{
	t_links		*link;
	int			shortest_distance;

	printf("first room = %s\n", new->room->name);
	shortest_distance = (*path)->room->distance;
	while (new->room->type != END)
	{
		link = new->room->links;
		new = get_shortest_link(new->room, shortest_distance, link);
		if (new->room->path == FALSE && new->room->links->shift == ON)
		{
			printf("new = %s\n", new->room->name);
			add_to_path(path, new);
			(*path)->steps_needed++;
		}
	}
}

void			find_path(t_path_data **path, t_ants **ants)//, t_amount **amount)
{
	t_path_data	*new;

	// (*amount)->path_amount += 1;
	*path = get_start(*ants);
	new = *path;
	create_path(path, new);
	new = NULL;
	free(new);
	// path_set(data_set, *path);
}
