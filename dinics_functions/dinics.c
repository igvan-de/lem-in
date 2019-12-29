/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dinics.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 11:53:49 by igvan-de       #+#    #+#                */
/*   Updated: 2019/12/29 18:41:11 by igvan-de      ########   odam.nl         */
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
	t_links		*tmp;

	probe = *path;
	if (probe == NULL || new == NULL)
		return ;
	while (probe->next != NULL)
		probe = probe->next;
	new->room->from = probe->room;
	probe->next = new;
	// printf("new room = %s\n", new->room->name);
	// printf("from = %s\n", new->room->from->name);
	probe->towards = new->room;
	printf("room = %s\ttowards = %s\n", probe->room->name, probe->towards->name);
	if (probe->room->from != NULL)
		printf("room = %s\tfrom = %s\n", probe->room->name, probe->room->from->name);
	probe->room->towards = new->room;
	tmp = probe->room->links;
	while (tmp != NULL)
	{
		if (ft_strequ(tmp->to->name, probe->towards->name) == TRUE)
			tmp->shift = ON;
		tmp = tmp->next;
	}
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
			new->room->path = TRUE; //need to change to amount of paths || want to put this in linked list of existing paths
		}
		link = link->next;
	}
	return (new);
}

static void		create_path(t_path_data **path, t_path_data *new)
{
	t_links		*link;
	int			shortest_distance;

	shortest_distance = (*path)->room->distance;
	while (new->room->type != END)
	{
		link = new->room->links;
		new = get_shortest_link(new->room, shortest_distance, link);
		add_to_path(path, new);
		(*path)->steps_needed++;
	}
}

void			find_path(t_path_data **path, t_path_set **data_set, t_ants **ants, t_amount **amount)
{
	t_path_data	*new;

	(*amount)->path_amount += 1;
	*path = get_start(*ants);
	new = *path;
	create_path(path, new);
	new = NULL;
	free(new);
	path_set(data_set, *path);
}




// static int	follow_direction(t_links *probe)
// {
// 	if (probe->to->visited == FALSE && probe->to->path == TRUE &&
// 	probe->to->towards->type != END)
// 	{
// 		if (probe->to->links->shift == ON)
// 		{
// 			probe->to->links->shift = OFF;
// 			printf("name = %s\tpath = %d\n", probe->to->name, probe->to->path);
// 			printf("path->shift = %d\n", probe->to->links->shift);
// 		}
// 		return (TRUE);
// 	}
// 	return (FALSE);
// }
