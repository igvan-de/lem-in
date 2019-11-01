# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: igvan-de <igvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/18 17:58:55 by igvan-de       #+#    #+#                 #
#    Updated: 2019/11/01 16:00:43 by igvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_YELLOW = $(shell printf "\e[33;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")

NAME = lem-in
SRCS = main.c read_input.c check_format.c hash_table.c
OBJ_FILES = $(SRCS:%.c=%.o)
INCLUDES = -I ./includes
CFLAGS = -Wall -Werror -Wextra
NORM = norminette $(SRCS) $(HEADER) | grep -e "Error" -e "Warning" -B 1
PRINT_PLUS = $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFAULT)')
PRINT_DONE = $(shell printf '$(COLOR_YELLOW)[ › ]$(COLOR_DEFAULT)')

all: $(NAME)

%.o: %.c includes/lemin.h
	@gcc $< -c -o $@ $(FLAGS) $(INCLUDES)

$(NAME): $(OBJ_FILES) libft/libft.a
	@gcc $(CFLAGS) $(OBJ_FILES) libft/libft.a -o $(NAME)
	@echo "$(PRINT_DONE) Compiling completed"

libft/libft.a:
	@make -C Libft
	@echo "$(PRINT_PLUS) Compiling libft"

clean:
	@rm -rf $(OBJ_FILES)
	@make -C ./Libft clean
	@echo "$(PRINT_PLUS) Cleaning objectives completed"

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean
	@echo "$(PRINT_PLUS) Cleaning all completed"

re: fclean all
	@echo "$(PRINT_PLUS) Recompiling completed"    

norm:
	@echo "===================NORMINETTE==================="
	@$(NORM) || echo "no norminette errors"
	@echo "================================================"
