/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dinics.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 11:53:49 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/21 14:59:58 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path	*get_start(t_ants *ants)
{
	t_path *start;

	start = (t_path*)ft_memalloc(sizeof(t_path));
	start->room = ants->begin;
	return (start);
}

t_path	*get_shortest_link(t_path *path, int shortest_distance, t_links *link)
{
	t_path *tmp;

	tmp = path;
	while (link != NULL)
	{
		printf("name = %s\n", link->to->name);
		printf("distance = %d\n", link->to->distance);
		printf("shotest_distance = %d\n", shortest_distance);
		if (link->to->distance < shortest_distance)
		{
			shortest_distance = link->to->distance;
			tmp->room = link->to;
			printf("tmp = %s\t pointer %p\n", tmp->room->name, tmp);
		}
		if (tmp->from == TRUE)
			break ;
		link = link->next;
	}
	return (tmp);
}

void	find_path(t_ants **ants)
{
	t_path	*path;
	t_links	*link;
	int		shortest_distance;

	path = get_start(*ants);
	printf("path->name = %s\n", path->room->name);
	printf("path->distance = %d\n", path->room->distance);
	shortest_distance = path->room->distance;
	while (path->room->links != NULL)
	{
		link = path->room->links;
		path->next = get_shortest_link(path, shortest_distance, link);
		path->room->path_id = TRUE;
		path->from = TRUE;
		path = path->next;
		if (path->room->type == END)
			break ;
	}
}
