/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:40:58 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:41:13 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	nb_args(char **args)
{
	int		size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

void	ft_echo_envv(char **cmdline, char **envs, int i)
{
	char	*value;

	if (cmdline[1][0] == '$' && cmdline[1][1] == '?')
		printf("%c\n", '0');
	value = find_value(&(cmdline[i][1]), envs);
	ft_putstr_fd(value, STDIN);
}

int	check_option_n(char *token)
{
	int	i;

	if (ft_strncmp(token, "-n", 2) != 0)
		return (0);
	i = 2;
	while (token[i])
	{
		if (token[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	helper(char **cmdline, int *i, int *val)
{
	while (check_option_n(cmdline[(*i)]))
	{
		(*val) = -1;
		(*i)++;
	}
}

void	ft_echo(char **cmdline, char **envs)
{
	int	i;
	int	val;

	i = 1;
	val = 0;
	if (nb_args(cmdline) > 1)
	{
		helper(cmdline, &i, &val);
		while (cmdline[i])
		{
			if (cmdline[i][0] == '\'')
				val = remove_char(cmdline[i], '\'');
			if (cmdline[i][0] == '$' && val != 1)
				ft_echo_envv(cmdline, envs, i);
			else
				ft_putstr_fd(cmdline[i], STDOUT);
			if (cmdline[i + 1] != NULL)
				ft_putchar_fd(' ', STDOUT);
			i++;
		}
	}
	if (val != -1)
		ft_putchar_fd('\n', STDOUT);
}
