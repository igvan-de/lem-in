/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lemin.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:16:29 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/24 16:33:29 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "get_next_line.h"
# include "libft.h"

typedef enum		e_type
{
	START = 0,
	END = 1,
	ROOM = 2,
	FALSE = 3,
	TRUE = 4,
}					t_type;

typedef struct		s_location
{
	int				x;
	int				y;
}					t_location;

typedef struct 		s_data
{
	char			*name;
	short			ant;
	t_location		location;
	t_type			type;

}					t_data;

typedef struct 		s_link
{
	t_data			room;
	struct s_data	*next;
}					t_link;

#endif