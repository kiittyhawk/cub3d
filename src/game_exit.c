/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:26:40 by nmordeka          #+#    #+#             */
/*   Updated: 2022/07/14 12:51:38 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	error_exit(char	*err_message, int exit_code)
{
	if (exit_code)
	{
		ft_putstr_fd("Error ", 1);
		if (err_message)
			ft_putendl_fd(err_message, 1);
		else
			ft_putendl_fd(strerror(errno), 1);
	}
	exit(exit_code);
}

static void	free_map(t_game *game)
{
	int	y;

	if (game->map)
	{
		y = -1;
		while (++y < game->height)
			free(game->map[y]);
		free(game->map);
	}
}

void	free_decor(t_decor *decor, void *mlx)
{
	if (!decor)
		return ;
	free_buffer(decor->south, mlx);
	free_buffer(decor->north, mlx);
	free_buffer(decor->east, mlx);
	free_buffer(decor->west, mlx);
	free (decor);
}

void	game_exit(t_game *game, char *err_mess, int code, int fd)
{
	if (game)
	{
		if (game->map)
			free_map(game);
		if (game->decor)
			free_decor(game->decor, game->mlx);
		if (game->buffer)
			free_buffer(game->buffer, game->mlx);
		if (game->dda)
			free(game->dda);
		if (game->camera)
			free(game->camera);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		free(game);
	}	
	if (fd > 0)
		close (fd);
	error_exit(err_mess, code);
}
