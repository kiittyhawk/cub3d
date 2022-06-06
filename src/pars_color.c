/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmordeka <nmordeka@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 07:44:33 by nmordeka          #+#    #+#             */
/*   Updated: 2022/05/16 00:08:21 by nmordeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	clear_arr(char **color_arr)
{
	int	i;

	if (color_arr)
	{
		i = -1;
		while (color_arr[++i])
			free (color_arr[i]);
		free (color_arr);
	}
	return (1);
}

int	check_arr(char	**color_arr)
{
	int	i;
	int j;

	i = -1;
	while (color_arr[++i])
	{
		j = -1;
		while (color_arr[i][++j])
			if (!(ft_isdigit(color_arr[i][j])) && (color_arr[i][j] != '\n'))
				return (0);
	}
	if (i != 3)
		return (0);
	return (1);
}

int	ft_pars_color(char	*str)
{
	char	**color_arr;
	int		r;
	int		g;
	int		b;
	
	color_arr = ft_split(str, ',');
	if (!color_arr)
		return (1);
	if (!check_arr(color_arr))
		return (clear_arr(color_arr));
	r = ft_atoi(color_arr[0]);
	g = ft_atoi(color_arr[1]);
	b = ft_atoi(color_arr[2]);
	clear_arr(color_arr);
	if (r > 255 || g > 255 || b > 255)
		return (1);
	return (255 << 24 | r << 16 | g << 8 | b);
}
