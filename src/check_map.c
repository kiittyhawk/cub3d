/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:49:15 by nmordeka          #+#    #+#             */
/*   Updated: 2022/07/19 12:33:08 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_empty_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

void	check_walls_around_space(t_game *all, char **map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while ((int)i < all->height - 1)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == ' ')
			{
				if ((j < ft_strlen(map[i - 1]) && (map[i - 1][j] != ' ' && \
					map[i - 1][j] != '1')) || \
					(!is_empty_space(map[i]) && j > 0 && \
					(map[i][j - 1] != ' ' && map[i][j - 1] != '1')) || \
					(j < ft_strlen(map[i + 1]) && (map[i + 1][j] != ' ' && \
					map[i + 1][j] != '1')) || \
					(!is_empty_space(map[i]) && j < ft_strlen(map[i]) && \
					(map[i][j + 1] != ' ' && map[i][j + 1] != '1')))
					game_exit(all, "map is not valid", 1, 2);
			}
			j++;
		}
		i++;
	}
}

void	fill_zero(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (game->map[++j])
	{
		i = -1;
		while (game->map[j][++i])
		{
			if (game->map[j][i] == ' ' && \
					(is_inside_walls_x(game->map, i, j, game) + \
					is_inside_walls_y(game->map, i, j, game)) == 4)
			{
				game->map[j][i] = '0';
			}
		}
	}
}

void	check_all_zeros(t_game *all, char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'W' || map[i][j] == 'E')
				if ((map[i - 1][j] == ' ' || !map[i - 1][j]) ||
					(map[i + 1][j] == ' ' || !map[i + 1][j]) ||
					(map[i][j - 1] == ' ' || !map[i][j - 1]) ||
					(map[i][j + 1] == ' ' || !map[i][j + 1]) ||
					(map[i + 1][j - 1] == ' ' || !map[i + 1][j - 1]) ||
					(map[i + 1][j + 1] == ' ' || !map[i + 1][j + 1]) ||
					(map[i - 1][j + 1] == ' ' || !map[i - 1][j + 1]) ||
					(map[i - 1][j - 1] == ' ' || !map[i - 1][j - 1]))
					game_exit(all, "map is not valid", 1, 2);
			j++;
		}
		i++;
	}
}

int	check_map(t_game *game)
{
	int	j;

	j = -1;
	ft_putendl_fd("Checking Map", 1);
	if (game->x < 0 || game->y < 0)
		return (print_message("No player position on map. "));
	while (game->map[++j])
		if (check_char(" 01NSWE", game->map[j]))
			game_exit(game, "map is not valid", 1, 2);
	fill_zero(game);
	check_all_zeros(game, game->map);
	check_walls_around_space(game, game->map);
	fill_zero_all(game);
	return (FT_TRUE);
}
