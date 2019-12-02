/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dinics.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 11:53:49 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/02 17:33:56 by igvan-de      ########   odam.nl         */
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
	int i;
	i = shortest_distance;

	tmp = path;
	while (link != NULL)
	{
		if (link->to->distance < shortest_distance && link->to->path_id == FALSE)
		{
			shortest_distance = link->to->distance;
			tmp->room = link->to;
			printf("shotest_distance = %d\n", shortest_distance);
			printf("tmp = %s\t pointer %p\n", tmp->room->name, tmp);
		}
		link = link->next;
	}
	return (tmp);
}

void	find_path(t_ants **ants)
{
	t_path	*path;
	t_table	*previous;
	t_links	*link;
	int		shortest_distance;

	path = get_start(*ants);
	shortest_distance = path->room->distance;
	previous = path->room;
	while (path != NULL) //check this while statement!
	{
		previous = path->room;
		link = path->room->links;
		path->next = get_shortest_link(path, shortest_distance, link);
		path->room->path_id = TRUE; //need to change to amount of paths
		path->room->links->direction = TRUE; //make pointer to room the path is going to!
		path->from = previous;
		if (path->room->type == END)
			break ;
		path = path->next;
	}
}
