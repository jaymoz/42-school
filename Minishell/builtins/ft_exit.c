/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:15:45 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:15:46 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mess_exit(void)
{
	ft_putstr_fd("exit\n", STDERR);
	exit(1);
}

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_command *cmd, char **cmdline)
{
	int	argc;

	argc = 0;
	if (cmd->preflag == 1)
		return ;
	while (cmdline[argc] != NULL)
		argc++;
	if (argc == 1)
		mess_exit();
	else if (argc > 2 && ft_isdigit_str(cmdline[1]))
	{
		ft_putstr_fd("exit\n", STDERR);
		print_execute_err_1("exit", "too many arguments");
		return ;
	}
	else
	{
		print_execute_err_2("exit", cmdline[1], "numeric argument required");
		exit(1);
	}
	mess_exit();
}
