/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_links.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:29:10 by igvan-de       #+#    #+#                */
/*   Updated: 2020/02/05 14:16:07 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*double_link function checks if there a double link is given*/
void		double_link(t_rooms *room_a, t_rooms *room_b)
{
	t_links	*links;

	links = room_a->links;
	while (links != NULL)
	{
		if (ft_strequ(links->room->name, room_b->name) == true)
		{
			ft_putendl("Error! Rooms already linked!");
			exit(-1);
		}
		links = links->next;
	}
}

/*This function gets the right room pointer*/
static t_rooms		*get_room(t_rooms **rooms, size_t size, char *name)
{
	t_rooms *room;
	size_t index;

	index = hash_function((unsigned char*)name, size);
	room = rooms[index];
	while (ft_strequ(room->name, name) == false)
		room = room->next;
	return (room);
}

/*This function adds a new link in front of linked list of links(connections) of a room*/
static void			add_link(t_links **link, t_links *new)
{
	if (link == NULL || new == NULL)
		return ;
	new->next = *link;
	*link = new;
}

/*This function creates a new link for a room*/
static t_links		*new_link(t_rooms *pointer)
{
	t_links	*link;

	link = (t_links*)ft_memalloc(sizeof(t_links));
	link->room = pointer;
	link->next = NULL;
	return (link);
}

/*This function sets the links to all rooms*/
void				set_links(t_rooms **rooms,
size_t size, char *name_a, char *name_b)
{
	t_rooms	*a;
	t_rooms	*b;

	a = get_room(rooms, size, name_a);
	b = get_room(rooms, size, name_b);
	double_link(a, b);
	add_link(&(a->links), new_link(b));
}
