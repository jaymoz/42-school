# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lross <lross@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 14:42:30 by lross             #+#    #+#              #
#    Updated: 2021/09/02 14:42:32 by lross            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -g  -Wall -Wextra -Werror -framework OpenGL -framework AppKit

INCLUDE = libft/libft.a minilibx_macos/libmlx.a

SRC = main.c draw.c read_file.c utils_2.c utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INCLUDE) -I fdf.h

clean:
	rm -f $(OBJ)
	make -C libft/ clean
	make -C minilibx_macos/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C libft/ fclean

re: fclean all

.PHONY:        all clean fclean re