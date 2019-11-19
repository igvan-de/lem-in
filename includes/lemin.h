/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lemin.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:16:29 by igvan-de       #+#    #+#                */
/*   Updated: 2019/11/19 14:14:21 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "get_next_line.h"
# include "libft.h"

# include <stdio.h> //REMOVE!!!!!!!!


typedef enum			e_return
{
	FALSE = 0,
	TRUE = 1
}						t_return;

typedef enum			e_found_existing
{
	FOUND = 1,
	EXISTING = 2
}						t_found_existing;

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

typedef struct			s_queue
{
	struct s_table		*to;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_ants //change name!
{
	int					start;
	int					finish;
	short				found_start;
	short				found_end;
	struct s_table		*end;
	struct s_table		*begin;
}						t_ants;

typedef	struct			s_rooms
{
	char				*name;
	int					x;
	int					y;
	short				start;
	short				end;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_links
{
	struct s_table		*to;
	struct s_links		*next;
}						t_links;

typedef struct			s_table
{
	char				*name;
	int					distance;
	short				visited;
	t_object_type		type;
	struct s_links		*links;
	struct s_table		*next;
}						t_table;

/*
**===============================READ FUNCTIONS=================================
*/
void					read_input(t_rooms **rooms, t_ants **ants);

/*
**===============================FORMAT FUNCTIONS===============================
*/
int						check_if_command(char *line, t_ants **ants);
int						check_format_room(char *line, t_ants **ants);
int						check_format_link(char *line, t_rooms **rooms);

void					is_start_or_end(char *line, t_ants **ants);
void					no_whitespaces(char *line);

/*
**===============================LIST FUNCTIONS=================================
*/
void					add_to_list(char *line, t_rooms **head, t_ants **ants);

/*
**===============================HASHTABLE FUNCTIONS============================
*/
size_t					hash_function(unsigned char *str, size_t size);

void					hash_table(t_table **table, t_rooms *room,
						t_ants **ants, size_t size);

/*
**===============================LINK FUNCTIONS=================================
*/
int						compare_with_rooms(char **a_b, t_rooms **rooms);

char					**lem_split(char *line, t_rooms **rooms);
char					**ft_split(char *line, int n, int c);

void					set_links(t_table **table,
						size_t size, char *name_a, char *name_b);

/*
**===============================BFS FUNCTIONS=================================
*/
t_queue					*create_end(t_ants *ants);
t_queue					*create_start(t_ants *ants);
t_queue					*new_element(t_table *pointer);

void					add_to_queue(t_queue **queue, t_queue *new);
void					pop_out_queue(t_queue **queue);
void					bfs(t_ants *ants);

/*
**==============================TEMPERARY PRINT FUNCTIONS=======================
*/
void					print_hash(t_table **table, size_t size);
void					print_rooms(t_rooms *rooms, t_ants **ants);
void					print_queue(t_queue *queue);

#endif
