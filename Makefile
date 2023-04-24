# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abasante <abasante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 09:35:42 by abasante          #+#    #+#              #
#    Updated: 2023/04/24 11:08:54 by abasante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

LIB_FLAGS	= -L ./libft -lft

INCLUDE	= -I ./includes

SOURCE = ./source/

MAP =		map/map.c map/validation.c map/update.c map/utils.c  map/render_player.c map/map_possible.c

WINDOW =	window/window.c

MOVEMENTS =		movements/left.c movements/right.c movements/up.c movements/down.c movements/utils.c

SRC =		$(addprefix $(SOURCE), $(MOVEMENTS) $(MAP) $(WINDOW) endgame.c images.c so_long.c)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:%.c=%.o)

$(NAME): $(OBJ)
	rm -rf $(NAME)
	make all -C ./libft
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIB_FLAGS)

clean:
	rm -rf $(OBJ)
	rm -rf ./a.out
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
