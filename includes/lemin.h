/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lemin.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:16:29 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/31 11:47:52 by igvan-de      ########   odam.nl         */
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

typedef struct			s_data
{
	char				*name;
	int					x;
	int					y;
}						t_data;

typedef struct			s_links
{
	struct s_rooms		*room;
	struct s_links		*next;
}						t_links;

typedef struct			s_hash_table
{
	int					count;
	int					size;
	t_data				**data;
	t_links				links;
	t_object_type		type;
}						t_hash_table;

/*
**===============================LIST FUNCTIONS=============================
*/
void			add_to_list(char *line, t_rooms **head, int index);
void			set_links(t_rooms **room, char *line);

/*
**===============================READ FUNCTIONS=============================
*/
void			read_input(t_rooms **rooms, t_ants **ants);

int				check_format_room(char *line);
int				check_format_link(char *line, t_rooms *rooms);
int				check_if_command(char *line);

#endif
