/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:43:30 by nmordeka          #+#    #+#             */
/*   Updated: 2022/07/14 18:57:29 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_decor	*init_decor(void)
{
	t_decor	*decor;

	decor = malloc(sizeof(t_decor));
	if (decor)
	{
		decor->south = NULL;
		decor->north = NULL;
		decor->east = NULL;
		decor->west = NULL;
		decor->ceiling = 0;
		decor->floor = 0;
	}
	return (decor);
}

t_game	*create_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->dda = malloc(sizeof(t_dda));
	if (!(*game).dda)
		return (NULL);
	game->decor = init_decor();
	if (!(*game).decor)
		return (NULL);
	game->x = -1;
	game->y = -1;
	game->camera = NULL;
	game->buffer = NULL;
	game->win = NULL;
	game->map = NULL;
	return (game);
}

void	game_print(t_game *game)
{
	int	i;

	ft_putendl_fd("Game.", 1);
	ft_putendl_fd("Player:", 1);
	ft_putstr_fd("X = ", 1);
	ft_putnbr_fd(game->x, 1);
	ft_putstr_fd(" , Y = ", 1);
	ft_putnbr_fd(game->y, 1);
	ft_putendl_fd("\nMap.", 1);
	ft_putstr_fd("width = ", 1);
	ft_putnbr_fd(game->width, 1);
	ft_putstr_fd(" , height = ", 1);
	ft_putnbr_fd(game->height, 1);
	ft_putchar_fd('\n', 1);
	i = -1;
	while (++i < game->height)
		ft_putendl_fd(game->map[i], 1);
}

t_game	*game_init(int fd)
{
	t_game	*game;

	game = create_game();
	if (!game)
		game_exit(game, "No enought mamory for game!", 4, fd);
	game->mlx = mlx_init();
	if (!game->mlx)
		game_exit(game, "Can't init MLX lib", 5, fd);
	game->buffer = init_buf(game->mlx, WIN_W, WIN_H, NULL);
	if (!game->buffer)
		game_exit(game, "Can't create screen buffer", 6, fd);
	if (!read_decor(game->decor, fd, game->mlx))
		game_exit(game, "Invalid textures or colors in map", 8, fd);
	read_map(game, fd);
	if (!game->map)
		game_exit(game, "No enought mamory for map!", 9, fd);
	fill_player(game);
	if (!check_map(game))
		game_exit(game, "map.", 10, fd);
	close (fd);
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "cub3D");
	if (!game->win)
		game_exit(game, "Can't init graphical window", 7, 0);
	game_print(game);
	return (game);
}
