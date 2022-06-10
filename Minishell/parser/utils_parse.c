/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:13:54 by lross             #+#    #+#             */
/*   Updated: 2022/01/06 17:13:55 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_white_space(char *input)
{
	int	space;
	int	i;

	space = 0;
	i = 0;
	if (input[0] == 0)
		return (1);
	while (input[i])
	{
		if (input[i] == '\r' || input[i] == '\v' || input[i] == '\t'
			|| input[i] == '\f')
			return (1);
		else if (input[i] == ' ')
			space++;
		i++;
	}
	if (space == (int)ft_strlen(input))
		return (1);
	return (0);
}

int	count_token(char *input)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_split(input, ' ');
	while (res[i])
	{
		i++;
	}
	free_double_str(res);
	return (i);
}

void	*initialize(char *input, t_data *data, t_list **head, t_ret *shell_ret)
{
	*head = ft_lstnew(NULL);
	data->lstlast = *head;
	data->cmd = ft_calloc(1, sizeof(t_command));
	if (!data->cmd)
		return (parse_error(data, NULL, MALLOC_ERROR, shell_ret));
	data->cmd->cmdlines = ft_calloc(count_token(input) + 1, sizeof(char *));
	if (!data->cmd->cmdlines)
		return (parse_error(data, NULL, MALLOC_ERROR, shell_ret));
	data->cmd->flag = 0;
	data->cmd->quote = 0;
	data->cmd->redir = 0;
	data->buff = ft_calloc(ft_strlen(input) + 1, sizeof(char));
	if (!data->buff)
		return (parse_error(data, NULL, MALLOC_ERROR, shell_ret));
	data->l_index = -1;
	data->b_index = 0;
	data->cmd_index = 0;
	return (NULL);
}
