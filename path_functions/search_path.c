/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_path.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 15:13:50 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/05 19:54:10 by igvan-de      ########   odam.nl         */
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
	new = existing;
	while (connections != NULL)
	{
		printf("connection->name =%s\tshift = %hd\tpath = %d\n", connections->to->name, connections->shift, connections->to->path);
		if (connections->shift == ON && connections->to->path == FALSE)
		{
			printf("connection->name =%s\n", connections->to->name);
			new->room = connections->to;
			new->room->path = TRUE;
		}
		connections = connections->next;
	}
	return (new);
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
	}
	connections = start->room->links;
	save_path(founded_paths, new);
	while (connections != NULL)
	{
		if (connections->shift == OFF && connections->to->path == FALSE)
			return (create_path(founded_paths, bfs_start));
		else
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
	printf("start = %s\n", start->room->name);
	while (new->room->type != END)
	{
		connections = new->room->links;
		new = follow_bfs(new, connections);
		bfs_path(&start, new);
		printf("after bfs new->name =%s\tshift = %hd\tpath = %d\n", new->room->name, new->room->links->shift, new->room->path);
	}
	create_path(founded_paths, start);
}
