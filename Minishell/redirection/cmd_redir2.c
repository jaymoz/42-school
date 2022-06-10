/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redir2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:14:07 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:54:44 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	helper_redir(int fdin, int fdout, t_redir *r)
{
	char	*line;
	char	*stop;

	stop = r->argv[r->argc - 1];
	proess_signal();
	close(fdin);
	while (1)
	{
		line = readline("\033[1;32m >\033[0m ");
		if (!ft_strncmp(line, stop, ft_strlen(stop) + 1))
			break ;
		ft_putendl_fd(line, fdout);
		free(line);
	}
	close(fdout);
}
