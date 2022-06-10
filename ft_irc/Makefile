NAME		= ircserv
SRCS		= main.cpp src/Channel.cpp src/Client.cpp src/Server.cpp src/Commands.cpp src/Parser.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= g++
CFLAGS		= -g -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re