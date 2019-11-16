/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_print.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 14:54:30 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/16 19:17:25 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


/*===============DELETE THIS FILE!!================*/
#include "lemin.h"
#include <stdio.h> 

void	print_rooms(t_rooms *rooms, t_ants **ants)
{
	printf("%d ants need to get from start to end or they will be eaten by a dragon.\n", (*ants)->start);
	while (rooms)
	{
		printf("Room: %s\t\tx: %d\t\ty: %d",
		rooms->name, rooms->x, rooms->y);
		if (rooms->start == 1)
			printf(" Start!\n");
		else if (rooms->end == 1)
			printf(" End!\n");
		else
			printf("\n");
		rooms = rooms->next;
	}
}

void    print_hash(t_table **table, size_t size)
{
    int i;

    i = 0;
    while (i < size)
    {
        while (table[i] != NULL)
        {
            printf("hash[%d] = \033[0;35m%s \033[0m", i, table[i]->name);
            if (table[i]->type == START)
                printf("(\033[0;34mstart\033[0m) ");
            else if (table[i]->type == END)
                printf("(\033[0;34mend\033[0m) ");
            if (table[i]->links != NULL)
                printf("which is pointing to");
            else
                printf("has no links..");
            while (table[i]->links)
            {
                printf(" \033[0;36m%s\033[0m", table[i]->links->to->name);
                if (table[i]->links->next)
                    printf(" &");
                table[i]->links = table[i]->links->next;
            }
            printf("\n");
            table[i] = table[i]->next;
        }
        i++;
    }
}
