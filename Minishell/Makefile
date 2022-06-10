NAME = minishell

FLAGS = -g -Wall -Wextra -Werror 

INCLUDE = libft/libft.a 

READLINE = -lreadline

SRC	= 	main.c \
			builtins/ft_echo.c\
			builtins/ft_env.c \
			builtins/ft_pwd.c \
			builtins/ft_cd.c \
			builtins/ft_exit.c \
			builtins/ft_export.c \
			builtins/ft_unset.c \
			execute/exec_process.c \
			utils/utils_envv.c \
			utils/utils_signal.c \
			utils/utils_execute.c \
			utils/export_utils.c \
			errors/envv_err.c \
			errors/execute_err.c \
			errors/exit_err.c \
			parser/parser.c \
			parser/parse_error.c \
			parser/utils_parse.c \
			redirection/cmd_redir.c \
			redirection/cmd_redir2.c \
			redirection/exec_redir.c \
			redirection/utils_redir.c \
			redirection/utils_redir2.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INCLUDE) $(READLINE) -I minishell.h

%.o: %.c
	gcc -c $< -g -o $@

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean


re: fclean all

.PHONY:        all clean fclean re