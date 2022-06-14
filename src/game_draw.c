/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:17:19 by nmordeka          #+#    #+#             */
/*   Updated: 2022/06/14 11:08:16 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_cub(t_game *game, int x, int y)
{
	y *= 20;
	x *= 20;
	int new_x = x;
	int new_y = y;
	while (y++ < new_y + 20)
	{
		x = new_x;
		while (x++ < new_x + 20)
			mlx_pixel_put(game->mlx, game->win, x, y, 0xffffff);
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
				put_cub(game, x, y);
			}
		}
	}
	
	return (0);
}
