/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:02:16 by lross             #+#    #+#             */
/*   Updated: 2021/09/01 19:51:59 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# define WIN_W 1000
# define WIN_H 1000

typedef struct s_fdf
{
	int		width;
	int		zoom;
	double	angle;
	int		z_scale;
	int		height;
	int		color;
	float	dx;
	float	dy;
	int		**z_matrix;
	int		shift_x;
	int		shift_y;
	int		iso;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

void	ft_set_pts(float *x, float *y, int *z, t_fdf *data);
void	ft_calc_max_step(float *max, t_fdf *data);
float	ft_max(float a, float b);
float	mod(float i);
void	isometric(float *x, float *y, int *z, t_fdf *data);
void	ft_error(void);
void	ft_legend(t_fdf *data);
void	ft_read_file(char *file_name, t_fdf *data);
void	ft_draw(t_fdf *data);

#endif