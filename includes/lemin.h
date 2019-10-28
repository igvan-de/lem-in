/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lemin.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:16:29 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/28 16:48:46 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "get_next_line.h"
# include "libft.h"

# define FALSE	0
# define TRUE	1

typedef enum		e_object_type
{
	FREE = 0,
	START = 1,
	END = 2,
	ANT = 3,
}					t_object_type;

typedef enum		e_node_value
{
	NAME = 0,
	X = 1,
	Y = 2,
}					t_node_value;

typedef struct		s_ants
{
	int				start;
	int				finish;
}					t_ants;

typedef struct		s_data
{
	char			*name;
	int				x;
	int				y;
	t_object_type	type;
}					t_data;

typedef struct		s_links
{
	int				*links;
	struct s_rooms	*next;
}					t_links;

typedef struct		s_rooms
{
	t_data			data;
	t_links			links;
	int				index;
	t_object_type	type;
	struct s_rooms	*next;
}					t_rooms;

/*
**===============================LIST FUNCTIONS=============================
*/
void	add_node(t_rooms **node, t_rooms *new);

t_rooms	*new_node(char *line, int index);

#endif