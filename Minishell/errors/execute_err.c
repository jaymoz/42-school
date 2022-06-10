/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:16:06 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:16:06 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	print_execute_err_1(char *token, char *err_msg)
{
	ft_putstr_fd("minishell", STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(token, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putendl_fd(err_msg, STDERR);
	return (-1);
}

int	print_execute_err_2(char *token1, char *token2, char *err_msg)
{
	ft_putstr_fd("minishell", STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(token1, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(token2, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putendl_fd(err_msg, STDERR);
	return (-1);
}
