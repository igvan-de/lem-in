/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_links.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:29:10 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/14 13:42:30 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_links		*new_link(t_table *pointer)
{
	t_links	*link;

	link = (t_links*)ft_memalloc(sizeof(t_links));
	link->to = pointer;
	return (link);
}

static void 		add_link(t_links **link, t_links *new)
{
	if (!link || !new)
		return ;
	new->next = *link;
	*link = new;
}

static t_table	*get_table(t_table **table, size_t size, char *name)
{
	t_table *t;
	size_t index;

	// VIND M SWS
	index = hash_function((unsigned char*)name, size);
	t = table[index];
	while (ft_strequ(t->name, name) == FALSE)
		t = t->next;
	return (t);
}

void			set_links(t_table **table, size_t size, char *nameA, char *nameB)
{
	t_table	*a;
	t_table	*b;

	a = get_table(table, size, nameA);
	b = get_table(table, size, nameB);
	add_link(&a->links, new_link(b));
}
