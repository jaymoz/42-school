/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:46:03 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 22:05:07 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	get_texture(t_cam *cam, t_ray *ray, t_tex *tex)
{
	if (ray->side == 0)
	{
		if (ray->raydir_x > 0)
			tex->tex_num = EA;
		else
			tex->tex_num = WE;
		tex->wall_x = cam->pos_y + ray->wall_dist * ray->raydir_y;
	}
	else
	{
		if (ray->raydir_y > 0)
			tex->tex_num = SO;
		else
			tex->tex_num = NO;
		tex->wall_x = cam->pos_x + ray->wall_dist * ray->raydir_x;
	}
	tex->wall_x -= floor(tex->wall_x);
	tex->tex_x = (int)(tex->wall_x * (double)TEXTUREWIDTH);
	if (ray->side == 0 && ray->raydir_x < 0)
		tex->tex_x = TEXTUREWIDTH - tex->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y > 0)
		tex->tex_x = TEXTUREWIDTH - tex->tex_x - 1;
}

void	copy_tex_color_to_buf(t_cam *cam, t_ray *ray, t_tex *tex, int x)
{
	int	y;
	int	tex_y;
	int	color;

	tex->step = 1.0 * TEXTUREHEIGHT / ray->line_height;
	tex->tex_pos
		= (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * tex->step;
	y = ray->draw_start - 1;
	while (++y < ray->draw_end)
	{
		tex_y = (int)tex->tex_pos & (TEXTUREHEIGHT - 1);
		tex->tex_pos += tex->step;
		color = cam->texture[tex->tex_num][TEXTUREHEIGHT * tex_y + tex->tex_x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		cam->buf[y][x] = color;
	}
}

void	draw_wall(t_data *data)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		init_cam(data->cam, data->ray, x);
		calc_side_dist(data->cam, data->ray);
		dda(data);
		calc_line_height(data->cam, data->ray);
		get_texture(data->cam, data->ray, data->tex);
		copy_tex_color_to_buf(data->cam, data->ray, data->tex, x);
	}
}
