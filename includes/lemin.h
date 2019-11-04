/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lemin.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:16:29 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/04 13:40:40 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "get_next_line.h"
# include "libft.h"


#include <stdio.h> //delete!

typedef enum			e_return
{
	FALSE = 0,
	TRUE = 1,
}						t_return;

typedef enum			e_object_type
{
	FREE = 0,
	START = 1,
	END = 2,
	ANT = 3,
}						t_object_type;

typedef enum			e_node_value
{
	NAME = 0,
	X = 1,
	Y = 2,
}						t_node_value;

typedef struct			s_ants
{
	int					start;
	int					finish;
}						t_ants;

typedef	struct 			s_rooms
{
	char				*name;
	int					x;
	int					y;
	struct s_room		*next;
}						t_rooms;

typedef struct			s_table
{
	int					*links;
	t_object_type		type;
	struct s_table		*next;
}						t_table;

/*
**===============================HASHTABLE FUNCTIONS=============================
*/
void			hashTable(t_rooms **table, t_rooms *room, size_t index);

int				create_size(size_t size);
size_t			hashFunction(unsigned char *str, size_t size);


/*
**===============================READ FUNCTIONS=============================
*/
void			read_input(t_table **table, t_rooms **rooms, t_ants **ants);

/*
**===============================FORMAT FUNCTIONS=============================
*/
int				check_format_room(char *line);
int				check_if_command(char *line);


void			add_to_list(char *line, t_rooms **head);


#endif
