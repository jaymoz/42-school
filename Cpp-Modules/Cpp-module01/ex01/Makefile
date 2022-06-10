NAME = ZombieHorde

FLAGS = -Wall -Wextra -Werror

SRC		=	Zombie.cpp \
			ZombieHorde.cpp \
			main.cpp
OBJ		=	$(SRC:.cpp=.o)

INCLUDE = Zombie.hpp

CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:        all clean fclean re
