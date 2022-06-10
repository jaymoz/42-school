/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:40:41 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 22:05:33 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	key_ar_l(t_cam *cam)
{
	double	old_dir_y;
	double	old_plane_y;
	double	rotate;

	rotate = cam->r_speed;
	old_dir_y = cam->dir_y;
	cam->dir_y = cam->dir_y * cos(rotate) - cam->dir_x * sin(rotate);
	cam->dir_x = old_dir_y * sin(rotate) + cam->dir_x * cos(rotate);
	old_plane_y = cam->plane_y;
	cam->plane_y = cam->plane_y * cos(rotate) - cam->plane_x * sin(rotate);
	cam->plane_x = old_plane_y * sin(rotate) + cam->plane_x * cos(rotate);
}

void	key_ar_r(t_cam *cam)
{
	double	old_dir_y;
	double	old_plane_y;
	double	rotate;

	rotate = cam->r_speed;
	old_dir_y = cam->dir_y;
	cam->dir_y = cam->dir_y * cos(-rotate) - cam->dir_x * sin(-rotate);
	cam->dir_x = old_dir_y * sin(-rotate) + cam->dir_x * cos(-rotate);
	old_plane_y = cam->plane_y;
	cam->plane_y = cam->plane_y * cos(-rotate) - cam->plane_x * sin(-rotate);
	cam->plane_x = old_plane_y * sin(-rotate) + cam->plane_x * cos(-rotate);
}
