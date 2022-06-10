/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:36:34 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 18:36:35 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_w(t_cam *cam, char **map)
{
	double	move_x;
	double	move_y;

	move_x = cam->dir_x * cam->m_speed;
	move_y = cam->dir_y * cam->m_speed;
	if (map[(int)(cam->pos_y + move_y)][(int)(cam->pos_x)] != '1')
		cam->pos_y += move_y;
	if (map[(int)(cam->pos_y)][(int)(cam->pos_x + move_x)] != '1')
		cam->pos_x += move_x;
}

void	key_s(t_cam *cam, char **map)
{
	double	move_x;
	double	move_y;

	move_x = cam->dir_x * cam->m_speed;
	move_y = cam->dir_y * cam->m_speed;
	if (map[(int)(cam->pos_y - move_y)][(int)(cam->pos_x)] != '1')
		cam->pos_y -= move_y;
	if (map[(int)(cam->pos_y)][(int)(cam->pos_x - move_x)] != '1')
		cam->pos_x -= move_x;
}

void	key_a(t_cam *cam, char **map)
{
	double	move_x;
	double	move_y;

	move_x = cam->dir_x * cam->m_speed;
	move_y = cam->dir_y * cam->m_speed;
	if (map[(int)(cam->pos_y - move_x)][(int)(cam->pos_x)] != '1')
		cam->pos_y -= move_x;
	if (map[(int)(cam->pos_y)][(int)(cam->pos_x + move_y)] != '1')
		cam->pos_x += move_y;
}

void	key_d(t_cam *cam, char **map)
{
	double	move_x;
	double	move_y;

	move_x = cam->dir_x * cam->m_speed;
	move_y = cam->dir_y * cam->m_speed;
	if (map[(int)(cam->pos_y + move_x)][(int)(cam->pos_x)] != '1')
		cam->pos_y += move_x;
	if (map[(int)(cam->pos_y)][(int)(cam->pos_x - move_y)] != '1')
		cam->pos_x -= move_y;
}
