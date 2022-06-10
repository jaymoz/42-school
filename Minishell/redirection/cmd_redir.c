/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:14:02 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:54:37 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_redir(t_command *cmd, t_redir *r, t_ret *shell_ret)
{
	int		fd;
	char	*path;

	fd = open(r->argv[r->argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (fd < 0)
	{
		ft_puterror_fd(r->argv[r->argc - 1], ": No such file or directory", 2);
		return (1);
	}
	path = find_path(r->cmds[0], g_env);
	if (!path)
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (!exec_builtin(cmd, r->cmds, shell_ret)
		&& (execve(path, r->cmds, g_env) == -1))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	free(path);
	free_double_arr(r->cmds);
	return (0);
}

static int	fd_dredir(t_command *cmd, t_redir *r, t_ret *shell_ret)
{
	int		fd;
	char	*path;

	fd = open(r->argv[r->argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0744);
	if (fd < 0)
	{
		ft_puterror_fd(r->argv[r->argc - 1], ": No such file or directory", 2);
		return (1);
	}
	path = find_path(r->cmds[0], g_env);
	if (!path)
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (!exec_builtin(cmd, r->cmds, shell_ret)
		&& (execve(path, r->cmds, g_env) == -1))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	free(path);
	free_double_arr(r->cmds);
	return (0);
}

static int	ft_bredir(t_command *cmd, t_redir *r, t_ret *shell_ret)
{
	int		fd;
	char	*path;

	fd = open(r->argv[r->argc - 1], O_RDONLY, 0644);
	if (fd < 0)
	{
		ft_puterror_fd(r->argv[r->argc - 1], ": No such file or directory", 2);
		return (1);
	}
	path = find_path(r->cmds[0], g_env);
	if (!path)
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	dup2(fd, STDIN_FILENO);
	close(fd);
	if (!exec_builtin(cmd, r->cmds, shell_ret)
		&& (execve(path, r->cmds, g_env) == -1))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	free(path);
	free_double_arr(r->cmds);
	return (0);
}

static int	ft_dbredir(t_command *cmd, t_redir *r, t_ret *shell_ret)
{
	pid_t	pid;
	int		fd[2];
	char	*path;

	if (pipe(fd) < 0)
		exit(1);
	pid = fork();
	if (pid == 0)
		helper_redir(fd[0], fd[1], r);
	else
	{
		path = find_path(r->cmds[0], g_env);
		if (!path)
			return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
		waitpid(pid, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (!exec_builtin(cmd, r->cmds, shell_ret)
			&& (execve(path, r->cmds, g_env) == -1))
			return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
		free(path);
		free_double_arr(r->cmds);
	}
	return (0);
}

void	cmd_redir(t_command *cmd, t_redir *r, t_ret *shell_ret)
{
	int		i;
	int		ret;
	int		status;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid == 0)
	{
		if (r->types[r->argc - 2] == REDIR)
			ret = ft_redir(cmd, r, shell_ret);
		else if (r->types[r->argc - 2] == DREDIR)
			ret = fd_dredir(cmd, r, shell_ret);
		else if (r->types[r->argc - 2] == DBREDIR)
			ret = ft_dbredir(cmd, r, shell_ret);
		else
			ret = ft_bredir(cmd, r, shell_ret);
		exit(ret);
	}
	wait(&status);
	shell_ret->err_num = status / 256;
	free(r->types);
	free_double_arr(r->argv);
	free_double_arr(r->cmds);
}
