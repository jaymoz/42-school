/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:14:52 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:14:53 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	message(void)
{
	char	*message;

	message = "\033[1;32mminishell >\033[0m ";
	write(1, message, ft_strlen(message));
}

static void	handle_signal(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		message();
	}
	if (signo == SIGQUIT)
	{
		ft_putstr_fd("\b\b  \b\b", 1);
	}
}

void	proess_signal(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}
