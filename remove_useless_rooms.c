/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_useless_rooms.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:28:43 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/28 12:53:10 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// static void	remove_room(t_table *probe)
// {
// 	t_table *tmp;

// 	// if (probe->type != END && probe->type != START)
// 	// {
// 		// if (probe->next != NULL)
// 		// {
// 		tmp = probe;
// 		free(tmp);
// 		tmp = NULL;
// 		probe = probe->next;
// 		// }
// 		// else
// 		// {
// 		// 	free(probe->name);
// 		// 	free(probe);
// 		// 	probe->name = NULL;
// 		// 	probe = NULL;
// 		// }
// 	// }
// }

static int	count_links(t_links *probe)
{
	int links;

	links = 0;
	printf("hoihoi\n");
	// if (ft_strcmp(probe->to->name, "5"))
	// 	return (2);
	while (probe)
	{
		probe = probe->next;
		links++;
	}
	return (links);
}

// void		iterate_hash(t_table *probe)
// {
// 	while (probe != NULL)
// 	{
// 		if ((probe->type != END && probe->type != START)
// 		&& count_links(probe->links) <= 1)
// 			remove_room(probe);
// 		if (probe != NULL)
// 			probe = probe->next;
// 		else
// 			break ;
// 	}
// }

void		delete_link(t_table *table, t_links **probe)
{
	t_links *tmp;
	t_links *tmp2;

	tmp = *probe;
	// head = probe->to->links;
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			printf("room name %s\n", tmp->to->name);
			if (table->name == tmp->to->name)
			{
				//printf("probe->to->next = %s\n", probe->to->links->next->to->name);
				//printf("probe->to->links = %p\n", probe->to->links);
				printf("tmp = %s\n", tmp->to->name);
				printf("tmp next = %p\n", tmp->next);
				tmp2 = tmp->next;
				free (tmp);
				tmp = NULL;
				tmp = tmp2;
				printf("hoiadjawffsf\n");
				//printf("tmp = %s\n", tmp->to->name);
				//printf("tmp next = %p\n", tmp->next);
				//printf("tmp pointer %p\n", tmp);
				// if (ft_strcmp(tmp->to->name, "7") == 0)
				// 	printf("tmp %s\n", tmp->to->name);
				// if (ft_strcmp(tmp->to->name, "7") == 0)
				// 	printf("tmp->next %s\n", tmp->next->to->name);
				// if (probe->to->links->next != NULL)
				// {
				// 	probe->to->links = probe->to->links->next;
				// 	probe->to->links = NULL;
				// }
				// else
				// {
				// 	printf("test\n");
				// 	probe->to->links = NULL;
				// }
				// free(probe->to->links);
				// while (probe)
				// {
				// 	printf("probe name = %s\n", (*probe)->to->name);
				// 	probe = (*probe)->next;
				// }
				// while (tmp)
				// {
				// 	printf("tmp name   = %s\n", tmp->to->name);
				// 	tmp = tmp->next;
				// }
				return ;
			}
			tmp = tmp->next;
		}
	}
	// return (probe);
	// table->links->to->links = head;
	// if (table->links)
	// {
	// 	while (table->links->to->links)
	// 	{
	// 		if (table->name == table->links->to->links->to->name)
	// 		{
	// 			links = table->links->to->links->next;
	// 			free(table->links->to->links);
	// 			table->links->to->links = NULL;
	// 			table->links->to->links = links;
	// 			return ;
	// 		}
	// 		table->links->to->links = table->links->to->links->next;
	// 	}
	// }
}

t_table		*delete_node(t_table *head)
{
	t_table *ret;
	t_links *tmp;
	t_links *tmp2;
	t_table *probe;

	if (!head)
		return (NULL);
	probe = head;
	printf("room = %s\n", head->name);
	if (head->type != END && head->type != START &&
	count_links(probe->links) <= 1)
	{
		tmp = head->links->to->links;
		printf("room %s has %d link(s) and will be removed.\n", head->name, count_links(head->links));
		tmp2 = tmp;
		delete_link(head, &tmp2);
		while (tmp)
		{
			printf("tmp2 = %s\n", tmp->to->name);
			tmp = tmp->next;
		}
		exit (0);
		ret = head->next;
		free(head);
        head->name = NULL;
        head = NULL;
		return (ret);
	}
	head->next = delete_node(head->next);
	return (head);
}

void		remove_useless_rooms(t_table **table, size_t size)
{
	size_t	i;
	t_table **probe;

	i = 0;
	probe = table;
	while (i < size)
	{
		probe[i] = delete_node(probe[i]);
		//printf("dowdawifiesfj\n");
		//iterate_hash(probe[i]);
		//printf("probe = %s\n", probe[i]->next->name);
		i++;
	}
	// printf("hoi\n");
	//print_hash(table, size);
	// printf("hoi\n");
	// exit(0);
}

