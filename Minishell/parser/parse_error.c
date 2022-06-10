/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:13:18 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:13:19 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	clear_ptr1(t_data *ptr1)
{
	if (ptr1->buff)
	{
		free(ptr1->buff);
		ptr1->buff = NULL;
	}
	if (ptr1->cmd->quote == 0)
	{
		if (ptr1->cmd)
		{
			if (ptr1->cmd->cmdlines)
			{
				free_double_str(ptr1->cmd->cmdlines);
				ptr1->cmd->cmdlines = NULL;
			}
			free(ptr1->cmd);
			ptr1->cmd = NULL;
		}
	}
}

void	free_double_str(char **ptr)
{
	int	idx;

	idx = 0;
	if (ptr)
	{
		while (ptr[idx])
		{
			free(ptr[idx]);
			ptr[idx] = NULL;
			idx++;
		}
		free(ptr);
		ptr = NULL;
	}
}

void	free_cmdline(void *content)
{
	t_command	*command;

	command = (t_command *)content;
	if (command)
	{
		if (command->cmdlines)
		{
			free_double_str(command->cmdlines);
			command->cmdlines = NULL;
		}
		free(command);
	}
}

void	*parse_error(t_data *ptr1, t_list *ptr2,
char *error, t_ret *shell_ret)
{
	if (ptr1)
		clear_ptr1(ptr1);
	if (ptr2)
	{
		ft_lstclear(&(ptr2->next), free_cmdline);
		free(ptr2);
	}
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	if (!ft_strncmp(error, SYNTAX_ERROR, ft_strlen(SYNTAX_ERROR)))
		shell_ret->ret = 2 * 256;
	else
		shell_ret->ret = 1 * 256;
	shell_ret->err_num = 0;
	return (NULL);
}
