/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:35:30 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 22:42:08 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	init_ns(t_data *data)
{
	if (data->p_dir == 'N' || data->p_dir == 'S')
	{
		data->cam->plane_x = -0.66;
		data->cam->plane_y = 0;
		data->cam->dir_x = 0;
		data->cam->dir_y = 1;
		if (data->p_dir == 'N')
		{
			data->cam->dir_y *= -1;
			data->cam->plane_x = 0.66;
		}		
	}
}

void	init_dir(t_data *data)
{
	init_ns(data);
	if (data->p_dir == 'W' || data->p_dir == 'E')
	{
		data->cam->plane_x = 0;
		data->cam->plane_y = 0.66;
		data->cam->dir_x = 1;
		data->cam->dir_y = 0;
		if (data->p_dir == 'W')
		{
			data->cam->dir_x *= -1;
			data->cam->plane_y = -0.66;
		}
	}
	data->cam->m_speed = 0.05;
	data->cam->r_speed = 0.05;
}

void	init_mlx(t_data *data)
{
	t_cam	*cam;

	cam = data->cam;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3d");
	cam->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	cam->img.data = (int *)mlx_get_data_addr(cam->img.img,
			&cam->img.bpp, &cam->img.size_l, &cam->img.endian);
	mlx_loop_hook(data->mlx, &ray_loop, data);
	mlx_hook(data->win, X_EVENT_KEY_PRESS, 0, &key_main, data);
	mlx_hook(data->win, 6, 1L << 0, &mouse_handler, data);
	mlx_hook(data->win, X_EVENT_KEY_EXIT, 0, &close_game, data);
	mlx_loop(data->mlx);
}

int	init_data(t_data *data)
{
	data->xpm_path[NO] = NULL;
	data->xpm_path[SO] = NULL;
	data->xpm_path[WE] = NULL;
	data->xpm_path[EA] = NULL;
	data->floor = 0;
	data->ceiling = 0;
	data->count = 0;
	data->p_dir = 0;
	data->p_flag = 0;
	data->m_row = 0;
	data->map = NULL;
	data->cam = (t_cam *)malloc(sizeof(t_cam));
	data->ray = (t_ray *)malloc(sizeof(t_ray));
	data->tex = (t_tex *)malloc(sizeof(t_tex));
	if (data->cam == NULL || data->ray == NULL || data->tex == NULL)
		return (print_err(ALLOC_ERR));
	data->cam->texture = NULL;
	return (0);
}
