/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lemin.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:16:29 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/29 16:20:21 by ygroenev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "get_next_line.h"
# include "libft.h"
# include <stdbool.h>

# include <stdio.h> //REMOVE!!!!!!!!

# define CURRENT_PATH_ROOM_LINKS get_last_room->room->links
# define PATH_ID (*path)->room->path_id
# define CONNECTED_ROOM_PATH_ID connected->room->path_id
# define CONNECTED_SHIFT connected->shift

typedef enum			e_object_type
{
	FREE = 0,
	START = 1,
	END = 2,
	ANT = 3,
	USELESS = 4
}						t_object_type;

typedef enum			e_node_value
{
	NAME = 0,
	X = 1,
	Y = 2,
	A = 0,
	B = 1,
	NOT_FOUND = 0,
	FOUND = 1,
	EXISTING = 2 ,
	OFF = 0,
	ON = 1
}						t_node_value;

typedef struct 			s_path_set
{
	int					path_size;
	struct s_path		*path;
	struct s_path_set	*next;
}						t_path_set;

typedef struct 			s_path
{
	struct s_rooms		*room;
	struct s_path		*next;
}						t_path;

typedef struct			s_queue
{
	struct s_rooms		*room;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_data
{
	int					amount_ants_start;
	short				found_start;
	short				found_end;
	int					turns;
	struct s_rooms		*end_room;
	struct s_rooms		*start_room;
}						t_data;

typedef	struct			s_input
{
	char				*name;
	int					x;
	int					y;
	short				start;
	short				end;
	struct s_input		*next;
}						t_input;

typedef struct			s_links
{
	short				end;
	short				shift; /*swift for turning link on or off*/
	struct s_rooms		*room;
	struct s_links		*next;
}						t_links;

typedef struct			s_rooms
{
	char				*name;
	int					distance;
	int					path_id;
	int					ant_id;
	short				visited;
	t_object_type		type;
	struct s_links		*links;
	struct s_rooms		*from;
	struct s_rooms		*towards;
	struct s_rooms		*branch;
	struct s_rooms		*next;
}						t_rooms;

/*
**===============================ANTS FUNCTIONS=================================
*/
int						calc_turn_amount(t_data *data, t_path_set *paths);
void					send_ants(t_data **data, t_path_set **paths, int turns);
void					get_ants(t_data **ants);

/*
**===============================FORMAT FUNCTIONS===============================
*/
bool					check_if_command(char *line, t_data **ants);
bool					check_format_room(char *line, t_data **ants);
bool					check_format_link(char *line, t_input **rooms);
bool					space_counter(char *line, int i, int space_count);
bool					dash_counter(char *line, int i, int dash_count);
void					is_start_or_end(char *line, t_data **ants);
void					no_whitespaces(char *line);

/*
**===============================LIST FUNCTIONS=================================
*/
void					add_to_list(char *line, t_input **head, t_data **data);

/*
**===============================HASHTABLE FUNCTIONS============================
*/
size_t					hash_function(unsigned char *str, size_t size);
void					hash_table(t_rooms **table, t_input *input,
						t_data **data, size_t size);

/*
**===============================LINK FUNCTIONS=================================
*/
int						compare_with_rooms(char **a_b, t_input **input);
char					**lem_split(char *line, t_input **input);
char					**ft_split(char *line, int n, int c);
void					get_links(t_input **input, t_rooms **rooms,
						char *line, size_t size);
void					set_links(t_rooms **rooms,
						size_t size, char *name_a, char *name_b);

/*
**===============================BFS FUNCTIONS==================================
*/
bool					bfs(t_rooms **rooms, t_data *data, size_t size);
void					create_queue(t_queue **queue);
void					add_to_queue(t_queue **queue, t_queue *new);
void					pop_out_queue(t_queue **queue);
t_queue					*create_start(t_data *data);
t_queue					*create_end(t_data *data);
t_queue					*new_element(t_rooms *room);

/*
**===============================PATH FUNCTIONS=================================
*/
void					create_paths_and_send_ants(t_rooms **rooms,
						t_data *data, size_t size);
void					save_paths(t_path_set **path_set, t_path_set *path);
// void					reset_path_ids(t_path_set **path);
void					reset_path_ids(t_rooms **rooms, size_t size);
void					reset_link_value(t_path **start);
void					follow_shifts(t_path **path, t_path_set *set);
void					follow_bfs(t_rooms **room);

/*
**===============================FREE FUNCTIONS=================================
*/
void 					free_queue(t_queue **queue);
void 					free_input(t_input **input);
void					free_set(t_path_set **path);
void 					free_path(t_path **path);
void 					free_path_set(t_path_set **set);
void					free_links(t_links **links);
void					free_rooms(t_rooms **rooms);

/*
**==============================TEMPORARY PRINT FUNCTIONS=======================
*/
void					print_hash(t_rooms **table, size_t size);
void					print_input(t_input *rooms, t_data **ants);
void					print_queue(t_queue *queue);
void					print_path(t_path *path);
void					print_path_set(t_path_set *path_set);


#endif
