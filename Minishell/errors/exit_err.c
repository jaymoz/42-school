/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:16:12 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:16:12 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_errno_err(char *err_msg)
{
	ft_putstr_fd("Error : ", STDERR);
	ft_putstr_fd(err_msg, STDERR);
	ft_putstr_fd("\n", STDERR);
	exit(1);
}
