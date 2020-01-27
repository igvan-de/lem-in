/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_print.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 14:54:30 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/16 14:23:14 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


/*===============DELETE THIS FILE!!================*/
#include "lemin.h"
#include <stdio.h>

void	print_input(t_input *rooms, t_data **ants)
{
	printf("%d ants need to get from start to end or they will be eaten by a dragon.\n", (*ants)->amount_ants_start);
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

void    print_hash(t_rooms **table, size_t size)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        while (table[i] != NULL)
        {
            printf("hash[%zu] = \033[0;35m%s \033[0m", i, table[i]->name);
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
                printf(" \033[0;36m%s\033[0m", table[i]->links->room->name);
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

// void	print_queue(t_queue *queue)
// {
// 	t_queue *test;

// 	test = queue;
// 	printf("============================\n");
// 	while (test != NULL)
// 	{
// 		printf("•••test = %s\t", test->to->name);
// 		printf("•••test->visisted = %d\t", test->to->visited);
// 		printf("•••test->distence = %d\n\n", test->to->distance);
// 		test = test->next;
// 	}
// 	/*place pop_out_queu function here*/
// 	printf("========AFTER POP=========\n");
// 	test = queue;
// 	while (test != NULL)
// 	{
// 		printf("test = %s\t", test->to->name);
// 		printf("test->visisted = %d\t", test->to->visited);
// 		printf("test->distence = %d\n\n", test->to->distance);
// 		test = test->next;
// 	}
// }

void				print_path_set(t_path_set *path_set)
{
	t_path_set	*probe_set;
    t_path      *probe_paths;

	probe_set = path_set;
	printf("--------NEW SET--------\n");
	while (probe_set != NULL)
	{
		probe_paths = probe_set->path;
		while (probe_paths != NULL)
		{
			if (probe_paths->room->towards != NULL)
			{
				printf("data->set->path = %s\ttowards = %s\tpath_id = %d\n",
				probe_paths->room->name, probe_paths->room->towards->name, probe_paths->room->path_id);
			}
			else
				printf("data->set->path = %s\tpath_id = %d\n", probe_paths->room->name, probe_paths->room->path_id);
			probe_paths = probe_paths->next;
		}
		printf("-----------------\n");
		probe_set = probe_set->next;
	}
}
