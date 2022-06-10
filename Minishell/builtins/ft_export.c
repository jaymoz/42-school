/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:15:50 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:15:50 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_sorted_env(char **env)
{
	int		i;
	char	**tab;

	tab = env;
	sort_env(tab, len_matrix(tab));
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	add_export(char *str, char **new, int i)
{
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
}

int	check_export(char *str, char ***envs)
{
	int		i;
	char	**new;

	if (str[0] == '=' || str[0] == '\0' || ft_strlen(str) == 1)
		return (-1);
	i = -1;
	while ((*envs)[++i] != NULL)
	{
		if (!ft_strncmp((*envs)[i], str, ft_strlen(str)))
		{
			(*envs)[i] = ft_strdup(str);
			return (1);
		}
	}
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		return (-1);
	i = -1;
	while ((*envs)[++i])
		new[i] = ft_strdup((*envs)[i]);
	add_export(str, new, i);
	*envs = new;
	return (1);
}

int	isvalid_export(char *key)
{
	int	i;

	i = -1;
	while (key[++i])
	{
		if (key[i] >= '0' && key[i] <= '9')
			return (0);
	}
	return (1);
}

void	ft_export(t_command *cmd, char **cmdline, t_ret *shell_ret)
{
	char	**tmp;
	int		i;
	int		val;

	val = 0;
	i = 0;
	tmp = cmdline;
	if (cmd->preflag == 1)
		return ;
	if (len_matrix(cmdline) == 1)
		print_sorted_env(g_env);
	else
	{
		remove_char(cmdline[1], '\'');
		while (cmdline[++i])
		{
			if (isvalid_export(ft_strtok(tmp[i], '=')) == 0)
				print_identifier_err("export", tmp[i]);
			remove_char(cmdline[i], '$');
			val = check_export(cmdline[i], &g_env);
		}
	}
	if (val != 1)
		shell_ret->ret = 1;
}
