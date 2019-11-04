/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_print.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 14:54:30 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/04 16:51:43 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_hash(t_table **table, size_t size)
{
	int i;

	i = 0;
	while (i < size)
	{
		while (table[i] != NULL)
		{
			printf("hash[%d] = %s\n", i, table[i]->name);
			table[i] = table[i]->next;
		}
		i++;
	}
}
