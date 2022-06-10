/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:15:32 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:25:57 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd_home(char *path, char **cmdline, char **envs)
{
	if (cmdline[1][1] == '~')
	{
		print_execute_err_2("cd", cmdline[1], "No such file or directory");
	}
	path = find_value("HOME", envs);
	if (chdir(path) == -1)
		print_execute_err_1("cd", "HOME not set");
	return (1);
}

int	ft_cd_envv(char *path, char **cmdline, char **envs)
{
	path = find_value(&(cmdline[1][1]), envs);
	if (chdir(path) == -1)
		chdir(find_value("HOME", envs));
	return (1);
}

void	set_oldpwd_pwd(char **envs)
{
	char	*cur_pwd;
	char	*old_pwd;
	char	*tmp;

	tmp = malloc(sizeof(char) * PATH_MAX);
	cur_pwd = ft_strjoin("PWD=", getcwd(tmp, PATH_MAX));
	old_pwd = ft_strjoin("OLDPWD=", find_value("PWD", envs));
	check_export(cur_pwd, &envs);
	check_export(old_pwd, &envs);
	free(cur_pwd);
	free(old_pwd);
}

void	ft_cd(char **cmdline, char **envs, t_ret *shell_ret)
{
	char	*path;
	int		val;

	path = 0;
	val = 0;
	if (nb_args(cmdline) > 1)
	{
		if (cmdline[1] != NULL && cmdline[1][0] != '~' && cmdline[1][0] != '$')
		{
			path = cmdline[1];
			if (chdir(path) == -1)
				val = print_execute_err_2("cd", path, strerror(errno));
			set_oldpwd_pwd(envs);
		}
		else if (cmdline[1] == NULL || cmdline[1][0] == '~')
			ft_cd_home(path, cmdline, envs);
		else if (cmdline[1][0] == '$')
			ft_cd_envv(path, cmdline, envs);
		if (val == -1)
			shell_ret->ret = 1;
		else
			shell_ret->ret = 0;
	}
}
