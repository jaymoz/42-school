/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:14:46 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:14:46 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_builtin(char **cmdline)
{
	if (!ft_strcmp(cmdline[0], "cd") || !ft_strcmp(cmdline[0], "echo")
		|| !ft_strcmp(cmdline[0], "pwd") || !ft_strcmp(cmdline[0], "env")
		|| !ft_strcmp(cmdline[0], "export") || !ft_strcmp(cmdline[0], "export")
		|| !ft_strcmp(cmdline[0], "unset") || !ft_strcmp(cmdline[0], "exit"))
		return (1);
	return (0);
}

int	remove_char(char *str, char c)
{
	int		new;
	int		i;

	new = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			str[new++] = str[i];
		i++;
	}
	str[new] = 0;
	return (1);
}
