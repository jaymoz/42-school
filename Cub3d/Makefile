# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lross <lross@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 18:00:51 by lross             #+#    #+#              #
#    Updated: 2022/03/19 22:34:15 by lross            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

NAME_BONUS = cub3d_bonus

FLAGS = -g  -Wall -Wextra -Werror -framework OpenGL -framework AppKit

INCLUDE = libft/libft.a 

MINILIBX = mlx/libmlx.a

SRC	= 	main.c\
		./utils/get_next_line.c\
		./utils/print_err.c\
		./utils/init.c\
		./utils/ft_split_set.c\
		./utils/free.c\
		./parse/parse_cub.c\
		./parse/parse_type.c\
		./parse/parse_map.c\
		./parse/parse_utils.c\
		./raycasting/raycasting.c\
		./raycasting/draw_wall.c\
		./raycasting/draw_util.c\
		./raycasting/draw_bg.c\
		./raycasting/dda.c\
		./key/key_main.c\
		./key/key_move.c\
		./key/key_rotate.c\
		

SRC_BONUS = 	./bonus/main_bonus.c\
				./bonus//utils/get_next_line_bonus.c\
				./bonus//utils/print_err_bonus.c\
				./bonus//utils/init_bonus.c\
				./bonus//utils/ft_split_set_bonus.c\
				./bonus//utils/free_bonus.c\
				./bonus//parse/parse_cub_bonus.c\
				./bonus//parse/parse_type_bonus.c\
				./bonus//parse/parse_map_bonus.c\
				./bonus//parse/parse_utils_bonus.c\
				./bonus//raycasting/raycasting_bonus.c\
				./bonus//raycasting/draw_wall_bonus.c\
				./bonus//raycasting/draw_util_bonus.c\
				./bonus//raycasting/draw_bg_bonus.c\
				./bonus//raycasting/dda_bonus.c\
				./bonus//key/key_main_bonus.c\
				./bonus//key/key_move_bonus.c\
				./bonus//key/key_rotate_bonus.c\
				./bonus//key/mouse_event_bonus.c\

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C mlx/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INCLUDE) $(MINILIBX)

%.o: %.c
	gcc -c $< -g -o $@

bonus: $(OBJ_BONUS)
	make -C libft/
	make -C mlx/
	gcc $(FLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(INCLUDE) $(MINILIBX)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C libft/ clean
	make -C mlx/ clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C libft/ fclean

re: fclean all

.PHONY:        all clean fclean re
