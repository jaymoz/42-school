NAME = 			minitalk
CLIENT = 		client
SERVER = 		server

CC =			gcc

FLAGS =			-Wall -Wextra -Werror -I minitalk.h

FLAGS_BONUS =   -Wall -Wextra -Werror -I minitalk_bonus.h

RM =			rm -rf


SRC =			src/ft_atoi.c \
				src/ft_check_number.c \
				src/ft_itoa.c \
				src/ft_putstr_fd.c \
				src/ft_strdup.c \
				src/ft_strjoin.c \
				src/ft_strlen.c \

OBJ = 			$(SRC:.c=.o)
C_FILE_CL =		client.c
C_FILE_SV = 	server.c
O_FILE_CL =		$(C_FILE_CL:.c=.o)
O_FILE_SV =		$(C_FILE_SV:.c=.o)

C_BONUS_FILE_CL =		client_bonus.c
C_BONUS_FILE_SV = 		server_bonus.c
O_BONUS_FILE_CL =		$(C_BONUS_FILE_CL:.c=.o)
O_BONUS_FILE_SV =		$(C_BONUS_FILE_SV:.c=.o)

all:			$(NAME)


$(NAME):		$(CLIENT) $(SERVER)

$(CLIENT):		$(OBJ) $(O_FILE_CL)
				$(CC) $(FLAGS) $(OBJ) $(O_FILE_CL) -o $(CLIENT)

$(SERVER):		$(OBJ) $(O_FILE_SV)
				$(CC) $(FLAGS) $(OBJ) $(O_FILE_SV) -o $(SERVER)

bonus:			$(OBJ) $(O_BONUS_FILE_SV) $(O_BONUS_FILE_CL)
				$(CC) $(FLAGS_BONUS) $(OBJ) $(O_BONUS_FILE_CL) -o $(CLIENT)
				$(CC) $(FLAGS_BONUS) $(OBJ) $(O_BONUS_FILE_SV) -o $(SERVER)


%.o: %.c
				$(CC) $(FLAGS) -c $< -o $@
clean:
				$(RM) $(OBJ)
				$(RM) $(O_FILE_CL)
				$(RM) $(O_FILE_SV)
				$(RM) $(O_BONUS_FILE_CL)
				$(RM) $(O_BONUS_FILE_SV)

fclean:			clean
				$(RM) $(CLIENT)
				$(RM) $(SERVER)
				

re:				fclean all

.PHONY:			all, clean, fclean, re