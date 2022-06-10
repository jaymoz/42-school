/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:36:25 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 22:05:42 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	close_game(t_data *data)
{
	free_all(0, NULL, data);
	mlx_destroy_image(data->mlx, data->cam->img.img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	key_esc(t_data *data)
{
	close_game(data);
}

int	key_main(int key, t_data *data)
{
	if (key == K_W)
		key_w(data->cam, data->map);
	if (key == K_A)
		key_a(data->cam, data->map);
	if (key == K_S)
		key_s(data->cam, data->map);
	if (key == K_D)
		key_d(data->cam, data->map);
	if (key == K_AR_L)
		key_ar_l(data->cam);
	if (key == K_AR_R)
		key_ar_r(data->cam);
	if (key == K_ESC)
		key_esc(data);
	return (0);
}
