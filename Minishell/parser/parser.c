/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:13:26 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:18:31 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	add_node(t_data *data, t_list *head, char *line, int symbol)
{
	data->cmd->flag = symbol;
	if (*(data->buff))
		copy_to_cmd(data);
	if ((data->cmd->cmdlines)[0] == 0 && data->cmd->flag <= 1)
		return (-1);
	else
	{
		ft_lstadd_back(&head, ft_lstnew(data->cmd));
		data->cmd = ft_calloc(1, sizeof(t_command));
		data->cmd->cmdlines = ft_calloc(count_token(line) + 1, sizeof(char *));
		data->lstlast = ft_lstlast(head);
	}
	data->cmd_index = 0;
	return (1);
}

void	copy_to_cmd(t_data *data)
{
	if (*(data->buff) == 0)
		return ;
	data->cmd->cmdlines[(data->cmd_index)] = ft_strdup(data->buff);
	data->cmd->cmdlines[(data->cmd_index) + 1] = NULL;
	(data->cmd_index)++;
	ft_bzero(data->buff, ft_strlen(data->buff) + 1);
	data->b_index = 0;
}

static void	handle_qoute(char *line, t_data *data)
{
	data->cmd->quote = 0;
	if (line[data->l_index] == '\'')
		data->buff[data->b_index++] = line[data->l_index];
}

void	parser2(char *line, t_data *data, t_list *head, t_ret *shell_ret)
{
	if (data->cmd->quote == line[data->l_index])
		handle_qoute(line, data);
	else if (data->cmd->quote == 0 && line[data->l_index] == '\"')
		data->cmd->quote = line[data->l_index];
	else if (data->cmd->quote == 0 && line[data->l_index] == '\'')
	{
		data->cmd->quote = line[data->l_index];
		data->buff[data->b_index++] = line[data->l_index];
	}
	else if (data->cmd->quote == 0 && line[data->l_index] == ' ')
		copy_to_cmd(data);
	else if (data->cmd->quote == 0 && line[data->l_index] == ';')
		shell_ret->err_num = add_node(data, head, line, 0);
	else if (data->cmd->quote == 0 && line[data->l_index] == '|')
		shell_ret->err_num = add_node(data, head, line, 1);
	else
	{
		if (data->cmd->quote == 0 && ft_strchr("><", line[data->l_index]))
			data->cmd->redir = 1;
		else if (data->cmd->quote != '\'' && line[data->l_index] == '\\'
			&& line[data->l_index + 1])
			data->l_index++;
		data->buff[data->b_index++] = line[data->l_index];
	}
}

void	*parse(char *line,	t_ret *shell_ret)
{
	t_data	data;
	t_list	*head;
	char	*new;

	new = ft_strtrim(line, " ");
	initialize(new, &data, &head, shell_ret);
	shell_ret->err_num = 1;
	while (new[++(data.l_index)])
	{
		parser2(new, &data, head, shell_ret);
		if (shell_ret->err_num < 1)
			return (parse_error(&data, head, SYNTAX_ERROR, shell_ret));
	}
	if (*(data.buff))
		copy_to_cmd(&data);
	if (data.cmd_index)
		ft_lstadd_back(&head, ft_lstnew(data.cmd));
	if (data.cmd->quote != 0)
		parse_error(&data, head, QUOTE_ERROR, shell_ret);
	free(data.buff);
	if (shell_ret->err_num == 1)
		exec_process(head, shell_ret);
	free(new);
	return (NULL);
}
