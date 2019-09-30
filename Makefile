# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 16:02:17 by pasosa-s          #+#    #+#              #
#    Updated: 2019/08/01 16:48:41 by pasosa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

MESSAGE = msj

FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
FLAGS2 = -framework OpenGL -framework AppKit

INC_DIR = ./inc
INCLUDES = -I ./inc/ -I ./libft/ -I ./minilibx/

LIBFT = ./libft/libft.a
LIBMLX = ./minilibx/libmlx.a

SRCDIR = ./src

SRCS = $(SRCDIR)/main.c \
	   $(SRCDIR)/get_values.c \
	   $(SRCDIR)/open_file.c \
	   $(SRCDIR)/split_to_list.c \
	   $(SRCDIR)/create_tab.c \
	   $(SRCDIR)/draw.c \
	   $(SRCDIR)/bresenham.c \
	   $(SRCDIR)/rotation.c \
	   $(SRCDIR)/gradient.c \
	   $(SRCDIR)/keyboard.c \
	   $(SRCDIR)/mouse_and_text.c \
	   $(SRCDIR)/feat.c \
	   $(SRCDIR)/free_mlx.c \

OBJ = $(SRCS:%.c=%.o)

NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

all: $(NAME)

$(NAME): $(MESSAGE) $(OBJ) $(LIBFT) $(LIBMLX)
	@$(CC) $(INCLUDES) $(LIBFT) $(LIBMLX) $(FLAGS) $(FLAGS2) $(OBJ) -o $@
	@echo "$(GREEN)compilation finished."

$(MESSAGE) :
	@echo "$(WHITE)\n     ------- $(NAME) -------\n"
	@echo "$(YELLOW)starting compilation"
	@echo "$(VIOLET)creating objects.."

$(LIBFT) :
	@make -C libft/ -s
	@echo "$(BLUE)libft.a created."

$(LIBMLX) :
	@make -C minilibx/ -s
	@echo "$(CYAN)libmlx.a created."


clean:
	@echo "$(WHITE)\n     ------- $@ -------\n"
	@rm -f $(OBJ)
	@echo "$(VIOLET)objects deleted"
	@make -C libft/ clean
	@echo "$(BLUE)libft objects deleted."
	@make -C minilibx/ clean
	@echo "$(CYAN)libmlx objects deleted."

fclean: clean
	@echo "$(WHITE)\n     ------- $@ -------\n"
	@rm -f $(NAME)
	@echo "$(WHITE)fdf deleted"
	@make -C libft/ fclean
	@echo "$(BLUE)libft.a deleted."

re: fclean all

.PHONY: all clean fclean re header
