NAME = philo

FLAGS = gcc -Wall -Wextra -Werror -g

SRC =  main.c parse_data.c utils2.c philo_life.c utils.c

SRC_OBJ = $(SRC:.c=.o)

$(NAME): $(SRC_OBJ)
		$(FLAGS) -o philo $(SRC_OBJ) -I philo.h

all: $(NAME)

clean:
		rm -rf ${SRC_OBJ}

fclean:
		rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re