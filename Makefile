# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: igvan-de <igvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/18 17:58:55 by igvan-de       #+#    #+#                 #
#    Updated: 2019/11/17 16:02:19 by igvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_RED = $(shell printf "\e[31;5;10m")
COLOR_YELLOW = $(shell printf "\e[33;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")

NAME = lem-in
SRCS = main.c read_input.c check_format.c hash_table.c list.c set_links.c \
	test_print.c start_end.c bfs.c
OBJ_FILES = $(SRCS:%.c=%.o)
INCLUDES = -I ./includes
CFLAGS = -Wall -Werror -Wextra -g #remore "-g", is for debugging!!
NORM = norminette $(SRCS) $(HEADER) | grep -e "Error" -e "Warning" -B 1
PRINT_PLUS = $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFAULT)')
PRINT_CLEAN = $(shell printf '$(COLOR_RED)[ - ]$(COLOR_DEFAULT)')
PRINT_DONE = $(shell printf '$(COLOR_YELLOW)[ › ]$(COLOR_DEFAULT)')

all: $(NAME)

%.o: %.c includes/lemin.h
	@gcc $< -c -o $@ $(CFLAGS) $(INCLUDES)
	@echo "$(PRINT_PLUS) $@"

$(NAME): $(OBJ_FILES) libft/libft.a
	@gcc $(CFLAGS) $(OBJ_FILES) libft/libft.a -o $(NAME)
	@echo "$(PRINT_DONE) Compiling completed"

libft/libft.a:
	@make -C Libft
	@echo "$(PRINT_PLUS) Compiling libft"

clean:
	@rm -rf $(OBJ_FILES)
	@make -C ./Libft clean
	@echo "$(PRINT_CLEAN) Cleaning objectives completed"

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean
	@echo "$(PRINT_CLEAN) Cleaning all completed"

re: fclean all   

norm:
	@echo "===================NORMINETTE==================="
	@$(NORM) || echo "no norminette errors"
	@echo "================================================"
