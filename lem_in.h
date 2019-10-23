#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef enum			e_object_type
{
	FREE,
	START,
	END,
}						t_object_type;

typedef struct			s_data
{
	char				*name;
	int					x;
	int					y;
	t_object_type 		type;
}						t_data;

typedef struct			s_links
{
	int					links;
	struct s_rooms		*next;
}						t_links;

typedef struct			s_rooms
{
	t_data				data;
	t_links				links;
	struct s_rooms		*next;
}						t_rooms;

#endif
