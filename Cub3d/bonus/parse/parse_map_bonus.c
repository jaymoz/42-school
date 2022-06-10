/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:46:03 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 22:05:19 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	put_map_line(t_data *data, char *line, int *i)
{
	if (line[ft_strlen(line) - 1] == '\n')
	{
		data->map[*i] = (char *)malloc(sizeof(char) * ft_strlen(line));
		if (data->map[*i] == NULL)
			return (print_err(ALLOC_ERR));
		ft_strlcpy(data->map[*i], line, ft_strlen(line));
	}
	else
	{
		data->map[*i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (data->map[*i] == NULL)
			return (print_err(ALLOC_ERR));
		ft_strlcpy(data->map[*i], line, ft_strlen(line) + 1);
	}
	(*i)++;
	return (0);
}

int	parse_map(t_data *data, char *file_path, int fd)
{
	int		m_flag;
	char	*line;
	int		i;

	data->map = (char **)malloc(sizeof(char *) * (data->m_row + 1));
	if (data->map == NULL)
		return (print_err(ALLOC_ERR));
	fd = open(file_path, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (check_type(line) == 2)
			m_flag = 1;
		if (m_flag == 1 && put_map_line(data, line, &i))
			free_all(fd, line, data);
		free(line);
	}
	data->map[data->m_row] = NULL;
	close(fd);
	return (0);
}

int	is_vaild(t_data *data, int i, int j)
{
	char	**map;

	map = data->map;
	if (i <= 0 || j <= 0 || i >= data->m_row || j >= (int)ft_strlen(map[i]))
		return (print_err(INVALID_MAP));
	if ((int)ft_strlen(map[i - 1]) < j || (int)ft_strlen(map[i + 1]) < j)
		return (print_err(INVALID_MAP));
	if (ft_isspace(map[i - 1][j]) || ft_isspace(map[i + 1][j])
		|| ft_isspace(map[i][j - 1]) || ft_isspace(map[i][j + 1]))
		return (print_err(INVALID_MAP));
	if (map[i - 1][j] == '\0' || map[i + 1][j] == '\0'
		|| map[i][j - 1] == '\0' || map[i][j + 1] == '\0')
		return (print_err(INVALID_MAP));
	return (0);
}

int	check_map(t_data *data)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			player = is_player(data, i, j);
			if (!ft_isspace(data->map[i][j]) && !player
				&& data->map[i][j] != '0' && data->map[i][j] != '1')
				return (print_err(INVALID_MAP));
			if (player == -1)
				return (print_err(TOO_MANY_PLAYER));
			if (player || data->map[i][j] == '0')
				if (is_vaild(data, i, j))
					return (1);
		}
	}
	if (!data->p_flag)
		return (print_err(NONE_PLAYER));
	return (0);
}
