NAME        = push_swap

SRCS_PATH    = srcs/

LIBFT_PATH    = libft/

LIBFT_LIB    = ./libft/libft.a

HEADERS_INC		= -I $(LIBFT_PATH)
HEADERS    = push_swap.h ./libft/libft.h

SRCS_FILES    = ft_push.c ft_reverse_rotate.c ft_rotate.c ft_swap.c main.c utils.c ft_sort.c utils_2.c utils_3.c ft_complex_sort.c

SRCS_OBJS     = ${SRCS_FILES:.c=.o}

CC         = gcc

CFLAGS         = -g -Wall -Wextra -Werror 

RM         = rm -f

AR         = ar crs

%.o : %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $(HEADERS_INC) $< -o $@

all:		pmake		${NAME}

${NAME}:    ${SRCS_OBJS} 
			${CC} ${CFLAGS}  ${SRCS_OBJS} ${LIBFT_LIB} -o ${NAME}

pmake:
			make -C libft/

clean:
			make -C ${LIBFT_PATH} clean
			${RM} ${SRCS_OBJS}

fclean: 	clean
			${RM} ${NAME} ${LIBFT_LIB} ${NAME}

re:         fclean all

.PHONY:        all clean fclean re