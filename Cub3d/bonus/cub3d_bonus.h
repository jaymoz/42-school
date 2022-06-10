/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:21:46 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 22:21:47 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "macro_bonus.h"

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deldist_x;
	double	deldist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_tex
{
	int		tex_num;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
}	t_tex;

typedef struct s_cam
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	m_speed;
	double	r_speed;

	int		**texture;
	int		buf[HEIGHT][WIDTH];
	t_img	img;
}	t_cam;

typedef struct s_data
{
	void	*mlx;
	void	*win;

	char	*xpm_path[4];
	int		floor;
	int		ceiling;
	int		count;
	int		mouse_old_x;

	char	p_dir;
	int		p_flag;
	int		m_row;
	char	**map;
	t_ray	*ray;
	t_cam	*cam;
	t_tex	*tex;
}	t_data;

int		print_err(int err_no);
char	*get_next_line(int fd);
int		init_data(t_data *data);
void	init_dir(t_data *data);
void	init_mlx(t_data *data);
int		init_texture(t_data *data);
char	**ft_split_set(char *s, char *charset);
void	free_all(int fd, char *line, t_data *data);
int		parse_cub(t_data *data, char *file_path);
int		parse_type(char *line, t_data *data);
int		parse_map(t_data *data, char *file_path, int fd);
int		check_map(t_data *data);
int		check_type(char *line);
int		check_color(char **split);
int		check_xpm(char **split);
int		check_extension(char *filename);
int		is_player(t_data *data, int i, int j);
int		ray_loop(t_data *data);
void	draw_wall(t_data *data);
void	init_cam(t_cam *cam, t_ray *ray, int x);
void	calc_side_dist(t_cam *cam, t_ray *ray);
void	dda(t_data *data);
void	calc_line_height(t_cam *cam, t_ray *ray);
void	get_texture(t_cam *cam, t_ray *ray, t_tex *tex);
void	copy_tex_color_to_buf(t_cam *cam, t_ray *ray, t_tex *tex, int x);
void	buf_to_img(t_data *data);
void	draw_floor_ceil(t_data *data, t_cam *cam);
int		key_main(int key, t_data *data);
void	key_w(t_cam *cam, char **map);
void	key_a(t_cam *cam, char **map);
void	key_s(t_cam *cam, char **map);
void	key_d(t_cam *cam, char **map);
void	key_ar_l(t_cam *cam);
void	key_ar_r(t_cam *cam);
int		close_game(t_data *data);
int		mouse_handler(int x, int y, void *param);

#endif