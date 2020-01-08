/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   value.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 16:55:41 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/08 12:50:52 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*This function find the room with type STRAT,
so we can later check if start if found in BFS*/
t_queue	*create_start(t_data *ants)
{
	t_queue *start;

	start = (t_queue*)ft_memalloc(sizeof(t_queue));
	start->to = ants->start_room;
	return (start);
}

/*This function is to get the room with type END for queue,
we need to function to start our BFS algorithm from end
and then culculate our way back to start*/
t_queue	*create_end(t_data *ants)
{
	t_queue *queue;

	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->to = ants->end;
	queue->to->visited = TRUE;
	return (queue);
}

/*This function creates a new element for the queue*/
t_queue	*new_element(t_rooms *pointer)
{
	t_queue	*queue;

	queue = (t_queue*)ft_memalloc(sizeof(t_queue));
	queue->to = pointer;
	return (queue);
}

/*This function is to get the room with type END for path*/
t_path_data	*get_end(t_path_data *path)
{
	t_path_data	*probe;

	if (path->room == NULL)
		return (path);
	probe = path;
	while (probe->room->type != END)
		probe = probe->next;
	return (probe);
}
