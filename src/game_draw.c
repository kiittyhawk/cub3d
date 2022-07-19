/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmordeka <nmordeka@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:17:19 by nmordeka          #+#    #+#             */
/*   Updated: 2022/07/11 18:40:12 by nmordeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_dda_tex(t_game *game, t_buffer *tex)
{
	t_dda	*dda;
	double	wallx;

	dda = game->dda;
	if (dda->side == 0)
		wallx = game->camera->pos_y + dda->dist_perpw * dda->ray_diry;
	else
		wallx = game->camera->pos_x + dda->dist_perpw * dda->ray_dirx;
	wallx -= floor(wallx);
	dda->texx = (int)(wallx * (double)tex->w);
	if (dda->side == 0 && dda->ray_dirx > 0)
		dda->texx = tex->w - dda->texx - 1;
	if (dda->side == 1 && dda->ray_diry < 0)
		dda->texx = tex->w - dda->texx - 1;
}

void	draw_vert_tex(int x, int length, t_buffer *tex, t_game *game)
{
	int				start;
	int				end;
	int				y;
	unsigned int	color;

	start = -length / 2 + WIN_H / 2;
	if (start < 0)
		start = 0;
	end = length / 2 + WIN_H / 2;
	if (end >= WIN_H)
		end = WIN_H - 1;
	set_dda_tex(game, tex);
	game->dda->step = 1.0 * tex->h / length;
	game->dda->tex_pos = (start - WIN_H / 2 + length / 2) * game->dda->step;
	y = start - 1;
	while (++y < end)
	{
		game->dda->texy = (int) game->dda->tex_pos & (tex->h - 1);
		game->dda->tex_pos += game->dda->step;
		color = buf_get_pixel(tex, game->dda->texx, game->dda->texy);
		buf_put_pixel(game->buffer, x, y, color);
	}
}

void	draw_line(int x, int length, char view, t_game *game)
{
	t_buffer	*texture;

	if (view == 'S')
		texture = game->decor->south;
	else if (view == 'N')
		texture = game->decor->north;
	else if (view == 'W')
		texture = game->decor->west;
	else
		texture = game->decor->east;
	draw_vert_tex(x, length, texture, game);
}

int	draw_buffer(t_game	*game)
{
	int		x;
	t_rect	rect;

	mlx_clear_window(game->mlx, game->win);
	buf_clear(game->buffer, 0);
	rect.base.x = 0;
	rect.base.y = 0;
	rect.w = WIN_W;
	rect.h = WIN_H / 2 - 1;
	buf_fill_rect(game->buffer, rect, game->decor->ceiling);
	rect.base.y = WIN_H / 2;
	rect.h = WIN_H / 2 - 1;
	buf_fill_rect(game->buffer, rect, game->decor->floor);
	x = -1;
	while (++x < WIN_W)
		print_line(x, game);
	mlx_put_image_to_window(game->mlx, game->win, game->buffer->data, 0, 0);
	return (0);
}
