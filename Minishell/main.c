/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:21:31 by lross             #+#    #+#             */
/*   Updated: 2022/01/04 20:39:13 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_env = NULL;

t_ret	*init_ret(void)
{
	t_ret	*new;

	new = (t_ret *)malloc(sizeof(t_ret));
	new->err_num = 0;
	new->ret = 0;
	return (new);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_ret	*shell_ret;
	int		ret_val;

	(void)argv;
	g_env = copy_envp(envp);
	shell_ret = init_ret();
	proess_signal();
	while (argc)
	{
		line = readline("\033[1;32mminishell >\033[0m ");
		if (!line)
			exit(EXIT_SUCCESS);
		if (line)
		{
			add_history(line);
			parse(line, shell_ret);
			free(line);
		}
	}
	ret_val = shell_ret->ret;
	free(shell_ret);
	free_double_str(g_env);
	return (ret_val);
}
