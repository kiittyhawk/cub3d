/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:55:42 by nmordeka          #+#    #+#             */
/*   Updated: 2022/06/15 13:21:37 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	player_move(int key, t_game *game)
{
	// mlx_clear_window(game->mlx, game->mlx->win);
	// // mlx_destroy_image(game->mlx->mlx, game->mlx->img);
	// if (key == KEY_DOWN)
	// {
	// 	game->player.y += sin(game->player.dir);
	// 	game->player.x += cos(game->player.dir);
	// 	// game->player.y += 1;
	// }
	// if (key == KEY_UP)
	// {
	// 	game->player.y -= sin(game->player.dir);
	// 	game->player.x -= cos(game->player.dir);
	// }
	// if (key == KEY_LEFT)
	// 	game->player.dir -= 0.1;
	// if (key == KEY_RIGHT)
	// 	game->player.dir += 0.1;
	// draw_buffer(game);
	(void)key;
	(void)game;
	return (0);
}
