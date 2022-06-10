/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:57:02 by lross             #+#    #+#             */
/*   Updated: 2021/09/19 16:24:51 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_util(int key, t_fdf *data)
{
	if (key == 5)
		data->z_scale += 1;
	if (key == 4)
		data->z_scale -= 1;
	if (key == 17)
		data->angle += 0.05;
	if (key == 16)
		data->angle -= 0.05;
	if (key == 24)
		data->zoom += 3;
	if (key == 27)
		data->zoom -= 3;
}

int	deal_key(int key, t_fdf *data)
{
	ft_key_util(key, data);
	if (key == 34)
		data->iso = 1;
	if (key == 35)
		data->iso = 0;
	if (key == 53)
		exit(0);
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_draw(data);
	return (0);
}

void	ft_initialise_data(t_fdf *data)
{
	data -> zoom = 10;
	data -> angle = 0.8;
	data -> z_scale = 1;
	data -> shift_x = (WIN_W / 3);
	data -> shift_y = (WIN_H / 3);
	data -> iso = 1;
	data -> mlx_ptr = mlx_init();
	data -> win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "t_fdf");
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		len;
	int		i;

	if (argc == 2)
	{
		i = 0;
		len = argc - 1;
		data = (t_fdf *)malloc(sizeof(t_fdf));
		ft_read_file(argv[1], data);
		ft_initialise_data(data);
		ft_draw(data);
		mlx_key_hook(data->win_ptr, deal_key, data);
		mlx_loop(data->mlx_ptr);
		while (i < data->height)
		{
			free(data->z_matrix[i]);
			i++;
		}
		free(data->z_matrix);
		free(data);
	}
	return (0);
}
