/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:56:48 by lross             #+#    #+#             */
/*   Updated: 2021/09/01 18:12:55 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_pts(float *x, float *y, int *z, t_fdf *data)
{
	(*z) = data->z_matrix[(int)(*y)][(int)(*x)];
	(*z) *= data->z_scale;
	(*x) *= (data->zoom);
	(*y) *= (data->zoom);
	if (data->iso)
	{
		isometric(x, y, z, data);
	}
	(*x) += (data->shift_x);
	(*y) += (data->shift_y);
}

void	ft_calc_max_step(float *max, t_fdf *data)
{
	(*max) = ft_max(mod(data->dx), mod(data->dy));
	(data->dx) /= (*max);
	(data->dy) /= (*max);
}
