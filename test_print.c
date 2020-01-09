/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_print.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 14:54:30 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/09 12:36:20 by igvan-de      ########   odam.nl         */
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

// void				print_path_set(t_path_set *data_set)
// {
// 	t_path_set	*probe_set;
// 	t_paths		*probe_paths;
// 	t_path_data	*probe_rooms;

// 	probe_set = data_set;
// 	while (probe_set != NULL)
// 	{
// 		probe_paths = probe_set->path;
// 		printf("data_set->set_id = %d\n", probe_set->set_id);
// 		// printf("tmp size = %zu\n", tmp->steps_needed);
// 		while (probe_paths != NULL)
// 		{
// 			probe_rooms = probe_paths->rooms;
// 			while (probe_rooms != NULL)
// 			{
// 				if (probe_rooms->room->towards != NULL)
// 				{
// 					printf("data->set->path = %s\ttowards = %s\n", probe_rooms->room->name, probe_rooms->room->towards->name);
// 					// if (tmp->room->links->shift == ON)
// 					// 	printf("data->set->path = %s\ttowards = %s\tshit = %hd\n", tmp->room->name, tmp->towards->name, tmp->room->links->shift);
// 				}
// 				else
// 					printf("data->set->path = %s\n", probe_rooms->room->name);
// 				probe_rooms = probe_rooms->next;
// 			}
// 			probe_paths = probe_paths->next;
// 		}
// 		probe_set = probe_set->next;
// 		printf("--------------------\n");
// 	}
// }
