/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmordeka <nmordeka@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:43:30 by nmordeka          #+#    #+#             */
/*   Updated: 2022/05/16 00:11:35 by nmordeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char		**read_map(int fd)
{
	char	**map;

	(void) fd;
	ft_putendl_fd("Read Map", 1);
	map = malloc(sizeof(char));
	return (map);
}

char		*check_map(char **map)
{
	//char	*err;
	
	(void) map;
	ft_putendl_fd("Checking Map", 1);
	return (NULL);
}

void	game_reset(t_game *game)
{
	game->win = NULL;
	game->decor = NULL;
	game->map = NULL;
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
	game->map = read_map(fd);
	if (!game->map)
		game_exit(game, "No enought mamory for map!", 8, fd);
	err_message = check_map(game->map);
	if (err_message)
		game_exit(game, err_message, 9, fd);
	return (game);
}
