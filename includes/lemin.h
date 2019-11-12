/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lemin.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:16:29 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/12 14:24:11 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "get_next_line.h"
# include "libft.h"

#include <stdio.h> //REMOVE!!!!!!!!


typedef enum			e_return
{
	FALSE = 0,
	TRUE = 1
}						t_return;

typedef enum			e_object_type
{
	FREE = 0,
	START = 1,
	END = 2,
	ANT = 3
}						t_object_type;

typedef enum			e_node_value
{
	NAME = 0,
	X = 1,
	Y = 2,
	A = 0,
	B = 1
}						t_node_value;

typedef struct			s_ants
{
	int					start;
	int					finish;
}						t_ants;

typedef	struct			s_rooms
{
	char				*name;
	int					x;
	int					y;
	struct s_rooms		*next;
}						t_rooms;

typedef struct 			s_links
{
	// char				*from;
	char				*to;
	struct s_links		*next;
}						t_links;

typedef struct			s_table
{
	char				*name;
	short				visited;
	// char				**links;
	t_object_type		type;
	struct s_links		*links;
	struct s_table		*next;
}						t_table;

/*
**===============================READ FUNCTIONS=================================
*/
void					read_input(t_table **table, t_rooms **rooms,
						t_ants **ants);

/*
**===============================FORMAT FUNCTIONS===============================
*/
int						check_if_command(char *line);
int						check_format_room(char *line);
int						check_format_link(char *line, t_table **table,
						size_t size);

/*
**===============================LIST FUNCTIONS=================================
*/
void					add_to_list(char *line, t_rooms **head);

/*
**===============================HASHTABLE FUNCTIONS============================
*/
void					hash_table(t_table **table, t_rooms *room, size_t size);

size_t					hash_function(unsigned char *str, size_t size);

/*
**===============================LINK FUNCTIONS=================================
*/
void					set_links(t_table **table, size_t size, char *nameA,
						char *nameB);

/*
**==============================TEMPERARY PRINT FUNCTIONS=======================
*/
void					print_hash(t_table **table, size_t size);
void					print_rooms(t_rooms *rooms, t_ants **ants);

#endif
