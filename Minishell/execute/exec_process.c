/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:16:18 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:16:18 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_child_process(t_command *cmd,
t_command *next_command, t_ret *shell_ret)
{
	int		val;
	char	*path;

	val = 0;
	path = find_path(cmd->cmdlines[0], g_env);
	if (cmd->flag == 1)
	{
		dup2(next_command->fds[1], STDOUT);
		close(next_command->fds[1]);
	}
	if (cmd->fds[0] != 0)
	{
		dup2(cmd->fds[0], STDIN);
		close(cmd->fds[0]);
	}
	if (check_builtin(cmd->cmdlines) == 1)
		exec_builtin(cmd, cmd->cmdlines, shell_ret);
	else
		(val = execve(path, cmd->cmdlines, g_env));
	if (val == -1)
		print_execute_err_1(cmd->cmdlines[0], "command not found");
	free(path);
	exit(val);
}

int	launch_other(t_list *cur_proc, t_command *cmd, t_ret *shell_ret)
{
	pid_t		pid;
	int			val;
	int			status;
	t_command	*next_command;
	char		*path;

	val = 0;
	path = find_path(cmd->cmdlines[0], g_env);
	next_command = cur_proc->content;
	if (cmd->flag == 1)
	{
		next_command = cur_proc->next->content;
		next_command->preflag = 1;
		pipe(next_command->fds);
	}
	pid = fork();
	if (pid == 0)
		exec_child_process(cmd, next_command, shell_ret);
	waitpid(pid, &status, 0);
	if (cmd->flag == 1)
		close(next_command->fds[1]);
	if (cmd->fds[0] != 0)
		close(cmd->fds[0]);
	free(path);
	return (val);
}

int	exec_builtin(t_command *cmd, char **cmdline, t_ret *shell_ret)
{
	if (!ft_strcmp(cmd->cmdlines[0], "cd"))
		ft_cd(cmdline, g_env, shell_ret);
	else if (!ft_strcmp(cmd->cmdlines[0], "echo"))
		ft_echo(cmdline, g_env);
	else if (!ft_strcmp(cmd->cmdlines[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(cmd->cmdlines[0], "env"))
		ft_env(g_env);
	else if (!ft_strcmp(cmd->cmdlines[0], "export"))
		ft_export(cmd, cmdline, shell_ret);
	else if (!ft_strcmp(cmd->cmdlines[0], "unset"))
		ft_unset(cmd, cmdline);
	else if (!ft_strcmp(cmd->cmdlines[0], "exit"))
		ft_exit(cmd, cmdline);
	else
		return (0);
	return (1);
}

void	exec_process(t_list *head, t_ret *shell_ret)
{
	t_list		*cur_proc;
	t_command	*cmd;

	cur_proc = head->next;
	while (cur_proc != NULL)
	{
		cmd = cur_proc->content;
		if (cmd->cmdlines[0])
		{
			if (cmd->redir == 1 && cmd->flag == 0)
			{
				launch_redir(cmd, cmd->cmdlines, shell_ret);
				break ;
			}
			if ((check_builtin(cmd->cmdlines) == 1) && cmd->flag == 0)
				exec_builtin(cmd, cmd->cmdlines, shell_ret);
			else
				launch_other(cur_proc, cmd, shell_ret);
		}
		cur_proc = cur_proc->next;
	}
	ft_lstclear(&head, free_cmdline);
}
