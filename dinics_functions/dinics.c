/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dinics.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 11:53:49 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/03 17:59:22 by igvan-de      ########   odam.nl         */
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
	// t_path_data *probe;

	// probe = *path;
	// while (probe != NULL)
	printf("new->room = %s\n", new->room->name);
	new->next = *path;
	*path = new;
	// return (probe);
}

static t_path_data	*get_shortest_link(t_path_data *path, int shortest_distance, t_links *link)
{
	t_path_data *tmp;

	tmp = path;
	while (link != NULL)
	{
		if (link->to->distance < shortest_distance && link->to->path_id == FALSE)
		{
			// printf("path->room = %s, %p\ n", path->room->name, path->room);
			shortest_distance = link->to->distance;
			path->towards = link->to;
			// printf("path->towards = %s, %p\n", path->towards->name, path->towards);
			tmp->room = link->to;
			// printf("shotest_distance = %d\n", shortest_distance);
			printf("tmp = %s\t pointer %p\n", tmp->room->name, tmp);
		}
		link = link->next;
	}
	return (tmp);
}

void	find_path(t_ants **ants)
{
	t_path_data	*path;
	t_path_data	*new;
	t_table	*previous;
	t_links	*link;
	int		shortest_distance;

	path = get_start(*ants);
	new = path;
	shortest_distance = path->room->distance;
	previous = path->room;
	while (path != NULL) //check this while statement!
	{
		previous = path->room;
		link = path->room->links;
		printf("path->start = %s\n", path->room->name);
		new->next = get_shortest_link(path, shortest_distance, link);
		new->room->path_id = TRUE; //need to change to amount of paths || want to put this in linked list of existing paths
		new->room->links->direction = TRUE; //make pointer to room the path is going to!
		new->from = previous;
		printf("path->room = %s\n", path->room->name);
		add_to_path(&path, new);
		if (path->room->type == END)
			break ;
		path = path->next;
	}
	// while (path != NULL)
	// {
	// 	printf("path = %s\n", path->room->name);
	// 	path = path->next;
	// }
	// path_set(path);
}
