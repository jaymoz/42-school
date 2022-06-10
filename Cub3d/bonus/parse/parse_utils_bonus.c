/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:46:03 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 22:05:25 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_xpm(char **split)
{
	int	i;

	i = 0;
	if (ft_strcmp(split[0], "NO") && ft_strcmp(split[0], "SO")
		&& ft_strcmp(split[0], "WE") && ft_strcmp(split[0], "EA"))
		return (1);
	while (split[i])
		i++;
	if (i > 2)
		return (1);
	i = open(split[1], O_RDONLY);
	if (i == -1)
		return (1);
	close(i);
	return (0);
}

int	check_color(char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split[++i])
	{
		if (ft_atoi(split[i], &j) == -1)
			return (1);
		if (j < 0 || j > 255)
			return (1);
		if (i > 3)
			return (1);
	}
	return (0);
}

int	check_type(char *line)
{
	int	i;

	i = -1;
	while (++i < (int)ft_strlen(line))
	{
		if (ft_isspace(line[i]))
			continue ;
		else if (ft_isalpha(line[i]))
			return (1);
		else if (ft_isdigit(line[i]))
			return (2);
		else
			return (3);
	}
	return (0);
}

int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (ft_strncmp(".cub", &filename[len - 4], 4))
		return (1);
	return (0);
}

int	is_player(t_data *data, int i, int j)
{
	char	c;

	c = data->map[i][j];
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (data->p_dir == 'N' || data->p_dir == 'S'
			|| data->p_dir == 'W' || data->p_dir == 'E')
			return (-1);
		data->p_dir = c;
		data->cam->pos_x = j + 0.5;
		data->cam->pos_y = i + 0.5;
		data->p_flag = 1;
		return (1);
	}
	return (0);
}
