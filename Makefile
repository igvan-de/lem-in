# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: igvan-de <igvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/18 17:58:55 by igvan-de       #+#    #+#                 #
#    Updated: 2020/02/05 12:38:08 by igvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include sources
include input_functions/sources
include hashtable_functions/sources
include bfs_functions/sources
include path_functions/sources
include free_functions/sources
include ants_calc/sources

COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_RED = $(shell printf "\e[31;5;10m")
COLOR_YELLOW = $(shell printf "\e[33;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")

NAME = lem-in
OBJ_FILES = $(SRCS:%.c=%.o)
INCLUDES = -I ./includes
CFLAGS =  -Wall -Werror -Wextra -g #remove -g!
NORM = norminette $(SRCS) | grep -e "Error" -e "Warning" -B 1
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
	@make -C libft/
	@echo "$(PRINT_PLUS) Compiling libft"

clean:
	@rm -f $(OBJ_FILES)
	@make -C ./Libft clean
	@echo "$(PRINT_CLEAN) Cleaning objectives completed"

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean
	@echo "$(PRINT_CLEAN) Cleaning all completed"

re:
	@make fclean
	@make all

norm:
	@echo "===================NORMINETTE==================="
	@$(NORM) || echo "no norminette errors"
	@echo "================================================"
