/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:43:30 by nmordeka          #+#    #+#             */
/*   Updated: 2022/06/14 11:08:21 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char		*check_map(t_game *game)
{
	(void) game;
	ft_putendl_fd("Checking Map", 1);
	return (NULL);
}

void	game_reset(t_game *game)
{
	game->win = NULL;
	game->decor = NULL;
	game->map = NULL;
}

void	game_print(t_game *game)
{
	ft_putendl_fd("Game.", 1);
	ft_putendl_fd("Player:", 1);
	ft_putstr_fd("X = ", 1);
	ft_putnbr_fd(game->player.x, 1);
	ft_putstr_fd(" , Y = ", 1);
	ft_putnbr_fd(game->player.y, 1);
	ft_putstr_fd(" , Point view = ", 1);
	ft_putchar_fd(game->point_view, 1);
	ft_putendl_fd("\nMap.", 1);
	ft_putstr_fd("width = ", 1);
	ft_putnbr_fd(game->width, 1);
	ft_putstr_fd(" , height = ", 1);
	ft_putnbr_fd(game->height, 1);
	ft_putchar_fd('\n', 1);
	int i = -1;
	while (++i < game->height)
		ft_putendl_fd(game->map[i], 1);
}

t_game	*game_init(int fd)
{
	t_game	*game;
	char	*err_message;

	game = malloc(sizeof(t_game));
	if (!game)
		game_exit(game, "No enought mamory for game!", 4, fd);
	game_reset(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		game_exit(game, "Can't init MLX lib", 5, fd);
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "cub3D");
	if (!game->win)
		game_exit(game, "Can't init graphical window", 6, fd);
	game->decor = read_decor(fd, game->mlx);
	if (!game->decor)
		game_exit(game, "Invalid textures or colors in map", 7, fd);
	read_map(game, fd);
	if (!game->map)
		game_exit(game, "No enought mamory for map!", 8, fd);
	err_message = check_map(game);
	if (err_message)
		game_exit(game, err_message, 9, fd);
	// game_print(game);
	return (game);
}
