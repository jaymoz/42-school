/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:54:05 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 21:57:55 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	init_buf_tex(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			data->cam->buf[i][j] = 0;
	}
	data->cam->texture = (int **)malloc(sizeof(int *) * 4);
	if (data->cam->texture == NULL)
		return (print_err(ALLOC_ERR));
	i = -1;
	while (++i < 4)
	{
		data->cam->texture[i] = (int *)malloc(sizeof(int)
				* (TEXTUREHEIGHT * TEXTUREWIDTH));
		if (data->cam->texture[i] == NULL)
			return (print_err(ALLOC_ERR));
		j = -1;
		while (++j < TEXTUREWIDTH * TEXTUREHEIGHT)
			data->cam->texture[i][j] = 0;
	}
	return (0);
}

void	get_image(t_data *data, int *texture, char *path, t_img *img)
{
	int	i;
	int	j;

	img->img = mlx_xpm_file_to_image(data->mlx, path,
			&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_l, &img->endian);
	i = -1;
	while (++i < img->img_height)
	{
		j = -1;
		while (++j < img->img_width)
			texture[img->img_width * i + j] = img->data[img->img_width * i + j];
	}
	mlx_destroy_image(data->mlx, img->img);
}

void	set_texture(t_data *data)
{
	t_img	img;
	int		i;

	i = -1;
	while (++i < 4)
		get_image(data, data->cam->texture[i], data->xpm_path[i], &img);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (print_err(INVALID_ARG));
	if (parse_cub(&data, argv[1]))
		free_all(0, NULL, &data);
	if (init_buf_tex(&data))
		free_all(0, NULL, &data);
	data.mlx = mlx_init();
	set_texture(&data);
	init_dir(&data);
	init_mlx(&data);
	return (0);
}
