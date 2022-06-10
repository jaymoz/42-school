/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:01:02 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 22:05:29 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	mouse_handler(int x, int y, void *param)
{
	t_data	*data;

	(void)y;
	data = (t_data *)param;
	if (x == data->mouse_old_x)
		return (0);
	if (x > data->mouse_old_x)
		key_ar_r(data->cam);
	else
		key_ar_l(data->cam);
	data->mouse_old_x = x;
	ray_loop(data);
	return (0);
}
