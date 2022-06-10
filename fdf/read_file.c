/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:56:54 by lross             #+#    #+#             */
/*   Updated: 2021/09/01 19:17:22 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_height(char *file_name)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (!fd)
		ft_error();
	height = 0;
	while (get_next_line(fd, &line) == 1)
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int	ft_get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (!fd)
		ft_error();
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	ft_get_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	ft_read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = ft_get_height(file_name);
	data->width = ft_get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	if (!fd)
		ft_error();
	i = 0;
	while (get_next_line(fd, &line))
	{
		ft_get_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	data->z_matrix[i] = NULL;
}
