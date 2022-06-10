/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:15:04 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:54:56 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/wait.h>
# include <signal.h>

# define STDIN 			0
# define STDOUT 		1
# define STDERR 		2
# define BREDIR			3
# define DBREDIR		4
# define REDIR			5
# define DREDIR			6
# define SYNTAX_ERROR	"Syntax error: near unexpected token!"
# define QUOTE_ERROR 	"The number of Quotes is odd!"
# define MALLOC_ERROR 	"Memory malloc fail!"
# define PIPE_ERROR 	"Pipe function is failed!"
# define FORK_ERROR 	"Fork function is failed!"

extern char	**g_env;

typedef struct s_ret
{
	int			err_num;
	int			ret;
}				t_ret;

typedef struct s_redir
{
	int			argc;
	char		**argv;
	char		**cmds;
	char		*types;
}				t_redir;

typedef struct s_command
{
	char		**cmdlines;
	int			flag;
	int			preflag;
	char		quote;
	int			fds[2];
	int			redir;
}				t_command;

typedef struct s_data
{
	t_list		*lstlast;
	t_command	*cmd;
	char		*buff;
	int			l_index;
	int			b_index;
	int			cmd_index;
}				t_data;

void	init_redir(char *command, t_redir *re);
int		parse_redir_final(t_redir *r, int j);
int		parse_redir(char *command, t_redir *r);
void	open_redir_files(t_redir *r);
void	launch_redir(t_command *cmd, char **cmdline, t_ret *shell_ret);
char	*ft_strjoin_c(char *s, char c);
char	*change_from_double_to_single_cmdline(char **cmdline);
char	*remove_single_quotes(char *str);
void	cmd_redir(t_command *cmd, t_redir *r, t_ret *shell_ret);
int		is_single_redir(char *command, int i);
int		find_redir_type(char *command, int i);
int		has_redir_syntax_error(char *str);
int		ft_puterror_fd(char *s1, char *s2, int fd);
char	*substr_and_trim(char *command, int start, int num, \
									char *charset);
void	free_double_arr(char **arr);
void	*parse(char *line, t_ret *shell_ret);
void	parser2(char *input, t_data *data, t_list *head, t_ret *shell_ret);
int		add_node(t_data *data, t_list *head, char *input, int symbol);
void	copy_to_cmd(t_data *data);
void	*initialize(char *input, t_data *data, t_list **head, t_ret *shell_ret);
int		count_token(char *input);
int		check_white_space(char *input);
void	*parse_error(t_data *ptr1, t_list *ptr2, char *error, t_ret *shell_ret);
void	free_cmdline(void *content);
void	free_double_str(char **ptr);
char	**copy_envp(char **envs);
void	sigint_handler(int sign_num);
char	*find_value(char *key, char **envs);
void	free_double_arr(char **arr);
char	*find_path(char *cmdline, char **envs);
int		check_builtin(char **cmdline);
int		remove_char(char *str, char c);
int		check_export(char *str, char ***envs);
void	exec_process(t_list *head, t_ret *shell_ret);
int		exec_builtin(t_command *cmd, char **cmdline, t_ret *shell_ret);
int		launch_other(t_list *cur_proc, t_command *cmd, t_ret *shell_ret);
void	exec_child_process(t_command *cmd, t_command *next_command, \
			t_ret *shell_ret);
void	ft_env(char **envs);
void	ft_pwd(void);
void	ft_cd(char **cmdline, char **envs, t_ret *shell_ret);
void	ft_echo(char **cmdline, char **g_envp);
void	ft_exit(t_command *cmd, char **cmdline);
void	ft_export(t_command *cmd, char **cmdline, t_ret *shell_ret);
void	ft_unset(t_command *cmd, char **cmdline);
void	print_errno_err(char *err_msg);
int		print_execute_err_1(char *token, char *err_msg);
int		print_execute_err_2(char *token1, char *token2, char *err_msg);
void	print_identifier_err(char *token1, char *token2);
void	proess_signal(void);
void	sort_env(char **tab, int env_len);
int		len_matrix(char **str);
int		nb_args(char **args);
void	helper_redir(int fdin, int fdout, t_redir *r);

#endif
