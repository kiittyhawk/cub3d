/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:17:19 by nmordeka          #+#    #+#             */
/*   Updated: 2022/06/14 11:31:41 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_cub(t_game *game, int x, int y, int color)
{
	y *= SCALE;
	x *= SCALE;
	int new_x = x;
	int new_y = y;
	while (y++ < new_y + SCALE)
	{
		x = new_x;
		while (x++ < new_x + SCALE)
			mlx_pixel_put(game->mlx, game->win, x, y, color);
	}
}

int	draw_buffer(t_game	*game)
{
	// (void) game;
	// put_cub(game);
	int y = -1;
	int x;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if ((int)game->map[y][x] == 49)
			{
				// mlx_pixel_put(game->mlx, game->win, x, y, 0xffffff);
				put_cub(game, x, y, 0xffffff);
			}
		}
	}
	put_cub(game, game->player.x, game->player.y, 0xfff);
	
	return (0);
}
