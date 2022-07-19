/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmordeka <nmordeka@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:29:02 by nmordeka          #+#    #+#             */
/*   Updated: 2022/07/12 12:14:25 by nmordeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	reset_camera(t_camera *camera, int x, int y)
{
	camera->pos_x = (double) x;
	camera->pos_y = (double) y;
	camera->dir_x = 0;
	camera->dir_y = 0;
	camera->plane_x = 0;
	camera->plane_y = 0;
	camera->angle_view = ANGLE;
}

t_camera	*camera_init(int x, int y, char view)
{
	t_camera	*res;

	res = malloc(sizeof(t_camera));
	reset_camera(res, x, y);
	if (view == 'N')
	{
		res->dir_y = -1;
		res->plane_x = 1 * res->angle_view;
	}
	else if (view == 'S')
	{
		res->dir_y = 1;
		res->plane_x = -1 * res->angle_view;
	}
	else if (view == 'W')
	{
		res->dir_x = -1;
		res->plane_y = -1 * res->angle_view;
	}
	else
	{
		res->dir_x = 1;
		res->plane_y = 1 * res->angle_view;
	}
	return (res);
}
