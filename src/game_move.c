/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:55:42 by nmordeka          #+#    #+#             */
/*   Updated: 2022/06/14 11:39:46 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	player_move(int key, t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	if (key == KEY_DOWN)
		game->player.y += 1;
	if (key == KEY_UP)
		game->player.y -= 1;
	if (key == KEY_LEFT)
		game->player.x -= 1;
	if (key == KEY_RIGHT)
		game->player.x += 1;
	draw_buffer(game);
	return (0);
}
