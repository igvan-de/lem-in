# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: igvan-de <igvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/18 17:58:55 by igvan-de       #+#    #+#                 #
#    Updated: 2019/10/18 18:17:03 by igvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_YELLOW = $(shell printf "\e[33;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")

NAME = lemin
CFLAGS = -Wall -Werror -Wextra
SRCS = 
OBJ_FILES = $(SRCS:%.c=%.o)
INCLUDES = -I ./includes
NORM = norminette $(SRCS) $(HEADER) | grep -e "Error" -e "Warning" -B 1
PRINT_PLUS = $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFAULT)')
PRINT_DONE = $(shell printf '$(COLOR_YELLOW)[ › ]$(COLOR_DEFAULT)')

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -o $@ $< -c

$(NAME): $(OBJ_FILES)
	@gcc $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "$(PRINT_DONE) Compiling completed"

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