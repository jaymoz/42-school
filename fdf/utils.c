/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:56:09 by lross             #+#    #+#             */
/*   Updated: 2021/09/01 18:04:37 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(void)
{
	ft_putstr_fd("Error opening file", 2);
	exit(1);
}

void	ft_legend(t_fdf *data)
{
	char	*legend;

	legend = "up, down, left, right: move";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 5, 0x03fc35, legend);
	legend = "i: isometric, p:parallel; +, -: zoom";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0x03fc35, legend);
	legend = "t,y: rotate map";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 35, 0x03fc35, legend);
	legend = "g,h: change altitude";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0x03fc35, legend);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	isometric(float *x, float *y, int *z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - (*z);
}
