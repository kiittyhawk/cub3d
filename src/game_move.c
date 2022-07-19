/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmordeka <nmordeka@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:55:42 by nmordeka          #+#    #+#             */
/*   Updated: 2022/07/12 12:10:38 by nmordeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate(t_camera *cam, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cam->dir_x;
	cam->dir_x = cam->dir_x * cos(angle) - cam->dir_y * sin(angle);
	cam->dir_y = old_dir_x * sin(angle) + cam->dir_y * cos(angle);
	old_plane_x = cam->plane_x;
	cam->plane_x = cam->plane_x * cos(angle) - cam->plane_y * sin(angle);
	cam->plane_y = old_plane_x * sin(angle) + cam->plane_y * cos(angle);
}

void	move(t_game *game, double dir_x, double dir_y, double speed)
{
	t_camera	*cam;

	cam = game->camera;
	if (game->map[(int)(cam->pos_y)][(int)(cam->pos_x + dir_x * speed)] == '0')
		cam->pos_x += dir_x * speed;
	if (game->map[(int)(cam->pos_y + dir_y * speed)][(int)(cam->pos_x)] == '0')
		cam->pos_y += dir_y * speed;
}

int	player_move(int key, t_game *game)
{
	t_camera	*cam;

	cam = game->camera;
	if (key == KEY_UP)
		move(game, cam->dir_x, cam->dir_y, MOVE_SPEED);
	else if (key == KEY_DOWN)
		move(game, cam->dir_x, cam->dir_y, -MOVE_SPEED);
	else if (key == KEY_RIGHT)
		move(game, (cam->dir_x * cos(1.5708) - cam->dir_y * sin(1.5708)), \
		(cam->dir_x * sin(1.5708) + cam->dir_y * cos(1.5708)), MOVE_SPEED);
	else if (key == KEY_LEFT)
		move(game, (cam->dir_x * cos(1.5708) - cam->dir_y * sin(1.5708)), \
		(cam->dir_x * sin(1.5708) + cam->dir_y * cos(1.5708)), -MOVE_SPEED);
	else if (key == KEY_RVIEW)
		rotate(game->camera, ROT_SPEED);
	else if (key == KEY_LVIEW)
		rotate(game->camera, -ROT_SPEED);
	return (0);
}
