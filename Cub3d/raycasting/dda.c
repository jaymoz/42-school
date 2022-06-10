/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:46:03 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 20:07:40 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_cam(t_cam *cam, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->raydir_x = cam->dir_x + cam->plane_x * ray->camera_x;
	ray->raydir_y = cam->dir_y + cam->plane_y * ray->camera_x;
	ray->map_x = (int)cam->pos_x;
	ray->map_y = (int)cam->pos_y;
	ray->deldist_x = fabs(1 / ray->raydir_x);
	ray->deldist_y = fabs(1 / ray->raydir_y);
	ray->step_x = 1;
	ray->step_y = 1;
}

void	calc_side_dist(t_cam *cam, t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x *= -1;
		ray->sidedist_x = (cam->pos_x - ray->map_x) * ray->deldist_x;
	}
	else
		ray->sidedist_x = (ray->map_x + 1.0 - cam->pos_x) * ray->deldist_x;
	if (ray->raydir_y < 0)
	{
		ray->step_y *= -1;
		ray->sidedist_y = (cam->pos_y - ray->map_y) * ray->deldist_y;
	}
	else
		ray->sidedist_y = (ray->map_y + 1.0 - cam->pos_y) * ray->deldist_y;
}

void	dda(t_data *data)
{
	t_ray	*ray;
	int		hit;

	ray = data->ray;
	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deldist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deldist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void	calc_line_height(t_cam *cam, t_ray *ray)
{
	if (!ray->side)
		ray->wall_dist
			= (ray->map_x - cam->pos_x + (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->wall_dist
			= (ray->map_y - cam->pos_y + (1 - ray->step_y) / 2) / ray->raydir_y;
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}
