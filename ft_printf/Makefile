NAME        = libftprintf.a

SRCS_PATH    = srcs/

LIBFT_PATH    = libft/

LIBFT_LIB    = libft.a

HEADERS_FOLDER    = includes/

SRCS_FILES    = \
	./srcs/ft_printf.c \
	./srcs/ft_check_specifier.c \
	./srcs/ft_justify.c \
	./srcs/ft_process_char.c \
	./srcs/ft_process_flags.c \
	./srcs/ft_process_format.c \
	./srcs/ft_process_hex.c \
	./srcs/ft_process_int.c \
	./srcs/ft_process_percentage.c \
	./srcs/ft_process_ptr.c \
	./srcs/ft_process_string.c \
	./srcs/ft_process_uint.c \
	./srcs/ft_set_list.c \
	./srcs/ft_update_struct.c \
	./srcs/ft_check.c \

SRCS_OBJS     = ${SRCS_FILES:.c=.o}

CC         = gcc

CFLAGS         = -Wall -Wextra -Werror

RM         = rm -f

AR         = ar crs

LIBFT_OBJS    = ${LIBFT_PATH}*.o

LIBFTMAKE    = $(MAKE) -C ${LIBFT_PATH}

all:				${NAME}

${NAME}:    ${SRCS_OBJS} pmake
			${AR} ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS}

pmake:
			${LIBFTMAKE}

clean:
			make -C ${LIBFT_PATH} clean
			${RM} ${SRCS_OBJS}

fclean: 	clean
			${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:         fclean all

.PHONY:        all clean fclean re
