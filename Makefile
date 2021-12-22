# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 13:09:07 by jhermon-          #+#    #+#              #
#    Updated: 2021/12/22 12:37:36 by jhermon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sample

SRC = main.c window.c image.c color.c hooks.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -Imlx

LINKS = -Lmlx -lmlx -lz -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
		gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)
		rm $(OBJ)

$(OBJ): $(SRC)
		gcc $(FLAGS) -c $(SRC)

exe: all
		./$(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

