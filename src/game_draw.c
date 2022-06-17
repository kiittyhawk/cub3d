/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:17:19 by nmordeka          #+#    #+#             */
/*   Updated: 2022/06/17 15:32:09 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ray_init(t_game *game)
{
	game->ray.hit = 0;
	game->ray.perpwalldist = 0;
	game->ray.dirX = -1;
	game->ray.dirY = 0;
	game->ray.planeX = 0;
	game->ray.planeY = 0.66;
	game->ray.rx = 200;
	game->ray.ry = 200;
	game->color = 0xfff;
	game->ray.camX = 2 * game->ray.x / (double)game->ray.rx - 1;
	game->ray.raydirX = game->ray.dirX + game->ray.planeX * \
						game->ray.camX;
	game->ray.raydirY = game->ray.dirY + game->ray.planeY * \
						game->ray.camX;
	game->ray.mapX = (int)game->ray.posX;
	game->ray.mapY = (int)game->ray.posY;
	game->ray.moveSpeed = 0.1;
	game->ray.rotSpeed = 0.033 * 1.8;
}

void	ray_init_more(t_game *game)
{
	if (game->ray.raydirY == 0)
		game->ray.deltadistX = 0;
	else if (game->ray.raydirX == 0)
		game->ray.deltadistX = 1;
	else
		game->ray.deltadistX = sqrt(1 + (game->ray.raydirY
			* game->ray.raydirY) / (game->ray.raydirX *
			game->ray.raydirX));
	if (game->ray.raydirX == 0)
		game->ray.deltadistY = 0;
	else if (game->ray.raydirY == 0)
		game->ray.deltadistY = 1;
	else
		game->ray.deltadistY = sqrt(1 + (game->ray.raydirX *
			game->ray.raydirX) / (game->ray.raydirY *
			game->ray.raydirY));
}

void	step_side_init(t_game *game)
{
	if (game->ray.raydirX < 0)
	{
		game->ray.stepX = -1;
		game->ray.sidedistX = (game->ray.posX - game->ray.mapX) \
							* game->ray.deltadistX;
	}
	else
	{
		game->ray.stepX = 1;
		game->ray.sidedistX = (game->ray.mapX + 1.0 - game->ray.posX) \
							* game->ray.deltadistX;
	}
	if (game->ray.raydirY < 0)
	{
		game->ray.stepY = -1;
		game->ray.sidedistY = (game->ray.posY - game->ray.mapY) \
							* game->ray.deltadistY;
	}
	else
	{
		game->ray.stepY = 1;
		game->ray.sidedistY = (game->ray.mapY + 1.0 - game->ray.posY) \
							* game->ray.deltadistY;
	}
}

void	incrementStep(t_game *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.sidedistX < game->ray.sidedistY)
		{
			game->ray.sidedistX += game->ray.deltadistX;
			game->ray.mapX += game->ray.stepX;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedistY += game->ray.deltadistY;
			game->ray.mapY += game->ray.stepY;
			game->ray.side = 1;
		}
		if (game->map[game->ray.mapX][game->ray.mapY] == '1')
			game->ray.hit = 1;
	}
}

void	drawStartEnd_init(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.perpwalldist = ((double)game->ray.mapX - \
				game->ray.posX + (1 - (double)game->ray.stepX) / 2) / game->ray.raydirX;
	else
		game->ray.perpwalldist = ((double)game->ray.mapY - \
				game->ray.posY + (1 - (double)game->ray.stepY) / 2) / game->ray.raydirY;
	game->ray.lineHeight = (int)(game->ray.ry / game->ray.perpwalldist);
	game->ray.drawStart = -game->ray.lineHeight / 2 + game->ray.ry / 2;
	if (game->ray.drawStart < 0)
		game->ray.drawStart = 0;
	game->ray.drawEnd = game->ray.lineHeight / 2 + game->ray.ry / 2;
	if (game->ray.drawEnd >= game->ray.ry || game->ray.drawEnd < 0)
		game->ray.drawEnd = game->ray.ry - 1;
}

void	get_color(t_game *game)
{
	int j;

	j = -1;
	while (++j < game->ray.drawStart)
		game->mlx.addr[j * game->mlx.line_l / 4 + game->ray.x] = game->color;
}

int	draw_buffer(t_game *game)
{
	game->ray.x = 0;
	
	while (game->ray.x < game->ray.rx)
	{
		ray_init(game);
		ray_init_more(game);
		step_side_init(game);
		incrementStep(game);
		drawStartEnd_init(game);
		get_color(game);
		mlx_put_image_to_window(game->mlx.mlx,game->mlx.win, game->mlx.img, 0, 0);
	}
	return (0);
}

