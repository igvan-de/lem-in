/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_links.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:29:10 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/08 14:09:51 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This function gets the right room pointer*/
static t_rooms		*get_input(t_rooms **table, size_t size, char *name)
{
	t_rooms *room;
	size_t index;

	index = hash_function((unsigned char*)name, size);
	room = table[index];
	while (ft_strequ(room->name, name) == FALSE)
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
	return (link);
}

/*This function sets the links to all rooms*/
void				set_links(t_rooms **table,
size_t size, char *name_a, char *name_b)
{
	t_rooms	*a;
	t_rooms	*b;

	a = get_input(table, size, name_a);
	b = get_input(table, size, name_b);
	add_link(&a->links, new_link(b));
}
