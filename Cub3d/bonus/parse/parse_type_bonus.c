/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:46:03 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 22:05:22 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	put_floor(char **split, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (split[++i])
	{
		data->floor = data->floor << 8;
		ft_atoi(split[i], &j);
		data->floor += j;
	}
}

void	put_ceiling(char **split, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (split[++i])
	{
		data->ceiling = data->ceiling << 8;
		ft_atoi(split[i], &j);
		data->ceiling += j;
	}
}

int	parse_xpm(char **split, t_data *data)
{
	if (check_xpm(split))
	{
		ft_free(split);
		return (print_err(INVALID_ELEMENT));
	}
	if (!ft_strcmp(split[0], "NO") && !data->xpm_path[NO])
		data->xpm_path[NO] = split[1];
	else if (!ft_strcmp(split[0], "SO") && !data->xpm_path[SO])
		data->xpm_path[SO] = split[1];
	else if (!ft_strcmp(split[0], "WE") && !data->xpm_path[WE])
		data->xpm_path[WE] = split[1];
	else if (!ft_strcmp(split[0], "EA") && !data->xpm_path[EA])
		data->xpm_path[EA] = split[1];
	else
		return (print_err(INVALID_ELEMENT));
	split[1] = NULL;
	data->count++;
	ft_free(split);
	return (0);
}

int	parse_color(char **split, t_data *data)
{
	int	i;

	i = 0;
	if (check_color(split))
	{
		ft_free(split);
		return (print_err(INVALID_ELEMENT));
	}
	if (!ft_strcmp(split[0], "F") && !data->floor)
		put_floor(split, data);
	else if (!ft_strcmp(split[0], "C") && !data->ceiling)
		put_ceiling(split, data);
	else
	{
		ft_free(split);
		return (print_err(INVALID_ELEMENT));
	}
	data->count++;
	ft_free(split);
	return (0);
}

int	parse_type(char *line, t_data *data)
{
	char	**split;

	split = ft_split_set(line, " \t\n\v\f\r,");
	if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
		return (parse_color(split, data));
	else
		return (parse_xpm(split, data));
}
