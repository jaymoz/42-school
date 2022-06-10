NAME = phonebook

FLAGS = -Wall -Wextra -Werror

SRC = tests.cpp Account.cpp 

OBJ = $(SRC:.cpp=.o)

INCLUDE = Account.hpp

CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:        all clean fclean re
