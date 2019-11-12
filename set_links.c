/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_links.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:29:10 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/12 13:48:13 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_links		*new_link(char *name)
{
	t_links	*link;

	link = (t_links*)ft_memalloc(sizeof(t_links));
	link->to = name;
	return (link);
}

static void			add_to_links(t_table **head, t_links *new)
{
	if (*head == NULL)
		return ;
	printf("add_to_links\n");
	new->next = (*head)->links;
	(*head)->links = new;
}

static t_table	*find_place(t_table **table, size_t size, char *nameA, char *nameB)
{
	size_t	index;

	index = hash_function((unsigned char*)nameA, size);
	while (table[index])
	{
		if (ft_strequ(table[index]->name, nameA) == TRUE)
		{
			table[index]->links = new_link(nameB);
			printf("table[%zu] = %s\t|| ", index, table[index]->name);
			printf("table[%zu]->link = %s\n", index, table[index]->links->to);
			return (table[index]);
		}
		table[index] = table[index]->next;
	}
	return (FALSE);
}

void			set_links(t_table **table, size_t size, char *nameA, char *nameB)
{
	t_table	*a;
	t_table	*b;

	a = find_place(table, size, nameA, nameB);
	printf("a->link = %p\n", a->links->to);
	// index = hash_function((unsigned char*)nameA, size); //typecast a_b[A] to (char)a_b[A]!! Check if this is really needed

}


	// *a->links = new_link(*b);































	// while (table[index] != NULL)
	// {
	// 	printf("test\n");
	// 	if (ft_strequ(table[index]->name, nameA) == TRUE)
	// 	{			
	// 		table[index]->links = new_link(nameB);
	// 		printf("if statement====================\n");
	// 		printf("table[%zu] = %s\t", index, table[index]->name);
	// 		printf("links = %s\n", table[index]->links->to);
	// 	}
	// 	table[index] = table[index]->next;
	// table[index]->links = a_b[B];
	// table[index]->links->to = a_b[B];
	// table[index]->links = table[index]->links->next;
