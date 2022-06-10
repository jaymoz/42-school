/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:56:38 by lross             #+#    #+#             */
/*   Updated: 2021/09/01 18:13:15 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_color(t_fdf *data, int *z2, int *z1)
{
	if ((*z2) || (*z1))
		(data->color) = 0xF3AF3D;
	else
		(data->color) = 0xffffff;
}

void	line2(float x1, float y1, t_fdf *data)
{
	float	max;
	int		z2;
	int		z1;
	float	x2;
	float	y2;

	x2 = (x1);
	y2 = (y1) + 1;
	ft_set_pts(&x1, &y1, &z1, data);
	ft_set_pts(&x2, &y2, &z2, data);
	data->dx = x2 - x1;
	data->dy = y2 - y1;
	ft_calc_max_step(&max, data);
	ft_set_color(data, &z2, &z1);
	while ((int)(x2 - x1) || (int)(y2 - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, data->color);
		x1 += (data->dx);
		y1 += (data->dy);
		if (x1 > WIN_W || y1 > WIN_H || y1 < 0 || x1 < 0)
			break ;
	}
}

void	line1(float x1, float y1, t_fdf *data)
{
	float	max;
	int		z2;
	int		z1;
	float	x2;
	float	y2;

	x2 = (x1) + 1;
	y2 = (y1);
	ft_set_pts(&x1, &y1, &z1, data);
	ft_set_pts(&x2, &y2, &z2, data);
	data->dx = x2 - x1;
	data->dy = y2 - y1;
	ft_calc_max_step(&max, data);
	ft_set_color(data, &z2, &z1);
	while ((int)(x2 - x1) || (int)(y2 - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, data->color);
		x1 += (data->dx);
		y1 += (data->dy);
		if (x1 > WIN_W || y1 > WIN_H || y1 < 0 || x1 < 0)
			break ;
	}
}

void	ft_draw(t_fdf *data)
{
	float	x;
	float	y;

	ft_legend(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				line1(x, y, data);
			if (y < data->height - 1)
				line2(x, y, data);
			x++;
		}
		y++;
	}
}
