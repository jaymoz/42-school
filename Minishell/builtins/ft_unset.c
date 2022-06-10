/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:15:57 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:45:05 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	isvalid_env(char *name)
{
	int	i;

	i = -1;
	while (name[++i])
	{
		if (ft_isalnum(name[i]) || name[i] == '_')
			;
		else
			return (0);
	}
	if (!i)
		return (0);
	return (1);
}

int	check_key_value(char *str, char *envs)
{
	int	i;

	i = 0;
	while (str[i] && envs[i] && (str[i] == envs[i]) && (envs[i] != '='))
		i++;
	if ((str[i] == '\0') && (envs[i] == '='))
		return (1);
	return (0);
}

int	unset_env(char *str, char ***envs)
{
	int	i;
	int	last;

	last = 0;
	while (((*envs)[last]) != NULL)
		last++;
	if (last < 1)
		return (-1);
	i = -1;
	while ((*envs)[++i] != NULL)
	{
		if (check_key_value(str, (*envs)[i]))
		{
			free((*envs)[i]);
			(*envs)[i] = ft_strdup((*envs)[last - 1]);
			free((*envs)[last - 1]);
			(*envs)[last - 1] = NULL;
			return (1);
		}
	}
	return (1);
}

void	ft_unset(t_command *cmd, char **cmdline)
{
	int	val;
	int	i;

	i = 0;
	val = 0;
	if (cmd->preflag == 1)
		return ;
	while (cmdline[++i])
	{
		remove_char(cmdline[i], '\'');
		if (isvalid_env(cmdline[i]))
			val = unset_env(cmdline[i], &g_env);
	}
}
