NAME = zombie

FLAGS = -Wall -Wextra -Werror

SRC		=	Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp \
			main.cpp

OBJ		=	$(SRC:.cpp=.o)

CC = c++

INCLUDE = Zombie.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:        all clean fclean re