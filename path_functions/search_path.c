/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_path.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 15:13:50 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/06 17:33:50 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_bfs	*get_start_bfs(t_ants *ants)
{
	t_bfs		*start;

	start = (t_bfs*)ft_memalloc(sizeof(t_bfs));
	start->room = ants->begin;
	return (start);
}

static t_path_data	*get_start_path_data(t_bfs *bfs_start)
{
	t_path_data	*start;

	start = (t_path_data*)ft_memalloc(sizeof(t_path_data));
	start->room = bfs_start->room;
	return (start);
}

static	t_path_data	*follow_shifts(t_path_data *existing, t_links *connections)
{
	t_path_data	*new;

	new = (t_path_data*)ft_memalloc(sizeof(t_path_data));
	new->room = existing->room;
	while (connections != NULL)
	{
		if (connections->to->links->shift == ON && connections->to->path == FALSE)
		{
			new->room = connections->to;
			printf("connection->name =%s\n", connections->to->name);
		}
		connections = connections->next;
	}
	return (new);
}

static void			add_to_path(t_path_data **start, t_path_data *new)
{
	t_path_data	*path;

	path = *start;
	if (path == NULL || new == NULL)
		return ;
	while (path->next != NULL)
		path = path->next;
	path->next = new;
	// if (path->room->type != END)
	path->room->path = TRUE;
}

static void			create_path(t_paths **founded_paths, t_bfs *bfs_start)
{
	t_path_data	*start;
	t_path_data	*new;
	t_links		*connections;

	start = get_start_path_data(bfs_start);
	new = start;
	while (new->room->type != END)
	{
		connections = new->room->links;
		new = follow_shifts(new, connections);
		add_to_path(&start, new);
	}
	save_path(founded_paths, start);
	connections = start->room->links;
	while (connections != NULL)
	{
		// if (connections->shift == OFF && connections->to->path == FALSE)
		// 	return (create_path(founded_paths, bfs_start));
		// else
			return ;
		connections = connections->next;
	}
}

void				search_paths(t_paths **founded_paths, t_ants **ants)
{
	t_bfs		*start;
	t_bfs		*new;
	t_links		*connections;

	start = get_start_bfs(*ants);
	new = start;
	while (new->room->type != END)
	{
		connections = new->room->links;
		new = follow_bfs(new, connections);
		bfs_path(&start, new);
	}
	create_path(founded_paths, start);
}
