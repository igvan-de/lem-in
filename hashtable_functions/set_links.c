/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_links.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:29:10 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/02 15:57:18 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_table		*get_table(t_table **table, size_t size, char *name)
{
	t_table *t;
	size_t index;

	index = hash_function((unsigned char*)name, size);
	t = table[index];
	while (ft_strequ(t->name, name) == FALSE)
		t = t->next;
	return (t);
}

static void			add_link(t_links **link, t_links *new)
{
	if (link == NULL || new == NULL)
		return ;
	new->next = *link;
	*link = new;
}

static t_links		*new_link(t_table *pointer)
{
	t_links	*link;

	link = (t_links*)ft_memalloc(sizeof(t_links));
	link->to = pointer;
	return (link);
}

void				set_links(t_table **table,
size_t size, char *name_a, char *name_b)
{
	t_table	*a;
	t_table	*b;

	a = get_table(table, size, name_a);
	b = get_table(table, size, name_b);
	add_link(&a->links, new_link(b));
}
