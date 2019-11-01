/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lemin.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:16:29 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/01 18:42:22 by igvan-de      ########   odam.nl         */
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

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	t_object_type		type;
	struct s_links		*links;
	struct s_room		*next;
}						t_room;

typedef struct			s_links
{
	struct s_rooms		*room;
	struct s_links		*next;
}						t_links;

typedef struct			s_hashTable
{
	t_room				**room;
}						t_hashTable;

/*
**===============================HASHTABLE FUNCTIONS=============================
*/
void			hashTable(t_hashTable **table, t_room *room, size_t index);

int				create_size(size_t size);
size_t			hashFunction(unsigned char *str, size_t size);


/*
**===============================READ FUNCTIONS=============================
*/
void			read_input(t_hashTable **room, t_ants **ants);

/*
**===============================FORMAT FUNCTIONS=============================
*/
int				check_format_room(char *line);
int				check_if_command(char *line);

#endif
