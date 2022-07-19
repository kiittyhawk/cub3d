/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:11:54 by jgyles            #+#    #+#             */
/*   Updated: 2022/07/19 12:34:19 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	print_message(char *str)
{
	ft_putstr_fd(str, 1);
	return (FT_FALSE);
}

int	check_char(char *targ, char *str)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (str[++i])
	{
		j = -1;
		while (targ[++j])
		{
			if (str[i] == targ[j])
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
			return (1);
		flag = 0;
	}
	return (0);
}

int	is_inside_walls_x(char **map, int x, int y, t_game *game)
{
	int	count;
	int	const_x;

	count = 0;
	const_x = x;
	while (x >= 0)
	{
		if (map[y][x] == '1')
		{
			count++;
			break ;
		}
		x--;
	}
	while (const_x < game->width)
	{
		if (map[y][const_x] == '1')
		{
			count++;
			break ;
		}
		const_x++;
	}
	return (count);
}

int	is_inside_walls_y(char **map, int x, int y, t_game *game)
{
	int	count;
	int	const_y;

	const_y = y;
	count = 0;
	while (y >= 0)
	{
		if (map[y][x] == '1')
		{
			count++;
			break ;
		}
		y--;
	}
	while (const_y < game->height)
	{
		if (map[const_y][x] == '1')
		{
			count++;
			break ;
		}
		const_y++;
	}
	return (count);
}

void	fill_zero_all(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (++j < game->height)
	{
		i = -1;
		while (++i < game->width)
		{
			if (game->map[j][i] == ' ')
				game->map[j][i] = '0';
		}
	}
}
