/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lemin.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:16:29 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/09 12:26:12 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "get_next_line.h"
# include "libft.h"

# include <stdio.h> //REMOVE!!!!!!!!

# define ROOM_START (*data)->start_room	/*check if this makes it quicker to get to the correct data*/
# define ROOM_END (*data)->end_room		/*check if this makes it quicker to get to the correct data*/
# define ROOM_CONNECTIONS (*queue)->room->links
# define CURRENT_ROOM (*queue)->room
# define CURRENT_ROOM_DISTANCE (*queue)->room->distance

typedef enum			e_return
{
	FALSE = 0,
	TRUE = 1,
	FINISHED = 0 /*ask Yonne if he agrees with this*/
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
	B = 1,
	NOT_FOUND = 0,
	FOUND = 1,
	EXISTING = 2 ,
	OFF = 0,
	ON = 1
}						t_node_value;

typedef struct			s_queue
{
	struct s_rooms		*room;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_data
{
	int					amount_ants_start;
	int					amount_ants_end;
	int					path_amount;
	int					max_path_amount;
	short				found_start;	/*Check if we calculate these values, if it makes our program faster. Because we could also check it with BFS. If BFS isnt possible anymore. Then we found the most possible amount of paths*/
	short				found_end;		/*Check if we calculate these values, if it makes our program faster. Because we could also check it with BFS. If BFS isnt possible anymore. Then we found the most possible amount of paths*/
	struct s_rooms		*end_room;
	struct s_rooms		*start_room;
}						t_data;

typedef	struct			s_input
{
	char				*name;
	int					x;
	int					y;
	short				start;	/*Ask Yonne why we have these variables as shorts and not as ints? Because amount of ants can be bigger then a short can handle?*/
	short				end;	/*Ask Yonne why we have these variables as shorts and not as ints? Because amount of ants can be bigger then a short can handle?*/
	struct s_input		*next;
}						t_input;

typedef struct			s_links
{
	short				shift; //0 als het geen link is tussen rooms uit 1 als aan het een link is tussen rooms
	struct s_rooms		*room;
	struct s_links		*next;
}						t_links;

typedef struct			s_rooms
{
	char				*name;
	int					distance;
	int					path_id; /*to know which room belongs to which path*/
	short				visited;
	t_object_type		type;
	struct s_links		*links;
	struct s_rooms		*towards;
	struct s_rooms		*next;
}						t_rooms;

/*
**===============================ANTS FUNCTIONS=================================
*/
void					get_ants(t_data **ants);

/*
**===============================FORMAT FUNCTIONS===============================
*/
int						check_if_command(char *line, t_data **ants);
int						check_format_room(char *line, t_data **ants);
int						check_format_link(char *line, t_input **rooms);
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
void					hash_table(t_rooms **table, t_input *room,
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
int						bfs(t_rooms **rooms, t_data *data, size_t size);
void					create_queue(t_queue **queue);
void					pop_out_queue(t_queue **queue);
t_queue					*create_start(t_data *data);
t_queue					*new_element(t_rooms *room);

/*
**===============================PATH FUNCTIONS=================================
*/


/*
**==============================TEMPERARY PRINT FUNCTIONS=======================
*/
void					print_hash(t_rooms **table, size_t size);
void					print_input(t_input *rooms, t_data **ants);
void					print_queue(t_queue *queue);
// void					print_path_set(t_path_set *data_set);



void		remove_link(t_rooms **table, size_t size);



#endif
