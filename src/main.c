/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:16:14 by nmordeka          #+#    #+#             */
/*   Updated: 2022/06/09 10:43:24 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	not_cub_ext(char *filename)
{
	char	*ext;
	int		result;

	if (!filename || ft_strlen(filename) < 5)
		return (FT_TRUE);
	ext = ft_substr(filename, ft_strlen(filename) - 4, 4);
	if (!ext)
		return (FT_TRUE);
	result = ft_strncmp(ext, ".cub", 4);
	free(ext);
	return (result);
}

int	key_hook(int key, t_game *game)
{
	if (key == KEY_ESC)
		game_exit(game, NULL, 0, 0);
	if (key == KEY_DOWN || key == KEY_UP || key == KEY_LEFT || key == KEY_RIGHT 
		|| key == KEY_LVIEW || key == KEY_RVIEW)
		player_move(key, game);
	return (0);
}

int	close_win_hook(t_game *game)
{
	game_exit(game, NULL, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	game = NULL;
	if (argc != 2)
		game_exit(game, "Program accept only one filename *.cub as parameter", 1, 0);
	if (not_cub_ext(argv[1]))
		game_exit(game, "Parameter hasn't .cub extention", 2, 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		game_exit(game, NULL, 3, 0);
	game = game_init(fd);
	int i = -1;
	while (game->map && game->map[++i] != NULL)
	{
		printf("%d\n", i);
		ft_putendl_fd(game->map[i], 1);
	}
	ft_putendl_fd("File OK", 1);
	mlx_hook(game->win, 17, 0, close_win_hook, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->mlx, draw_buffer, game);
	mlx_loop(game->mlx);
	return (0);
}