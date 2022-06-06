/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmordeka <nmordeka@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:54:02 by nmordeka          #+#    #+#             */
/*   Updated: 2022/05/16 00:10:49 by nmordeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_floor(char type, char *str, t_decor *decor)
{
	if (type == 'F' && decor->floor > 0)
		decor->floor = ft_pars_color(str);
	else if (decor->ceiling > 0)
		decor->ceiling = ft_pars_color(str);
}

static void	fill_texture(char type, char *str, t_decor *decor, void *mlx)
{
	if (type == 'S' && !(decor->south))
		decor->south = ft_sprite_init(str, mlx);
	else if (type == 'N' && !(decor->north))
		decor->north = ft_sprite_init(str, mlx);
	else if (type == 'E' && !(decor->east))
		decor->east = ft_sprite_init(str, mlx);
	else if (type == 'W' && !(decor->west))
		decor->west = ft_sprite_init(str, mlx);
}

static void	fill_decor(char *str, t_decor *decor, void *mlx)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] == ' ')
		i++;
	if (!str[i] || str[i] == '\n')
		return ;
	if (str[i] == 'F' && str[i + 1] == ' ')
		fill_floor('F', &str[i + 2], decor);
	else if (str[i] == 'C' && str[i + 1] == ' ')
		fill_floor('C', &str[i + 2], decor);
	else if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		fill_texture('N', &str[i + 3], decor, mlx);
	else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		fill_texture('S', &str[i + 3], decor, mlx);
	else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		fill_texture('W', &str[i + 3], decor, mlx);
	else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		fill_texture('E', &str[i + 3], decor, mlx);
}

static	int	check_fill(t_decor *dec)
{
	if (dec->south && dec->north && dec->east && dec->west \
		&& dec->ceiling <= 0 && dec->floor <= 0)
		return (1);
	return (0);
}

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
		decor->ceiling = 1;
		decor->floor = 1;
	}
	return (decor);
}

t_decor		*read_decor(int fd, void *mlx)
{
	t_decor	*decor;
	char	*str;

	ft_putendl_fd("Read Decor", 1);
	decor = init_decor();
	if (decor)
	{
		str = get_next_line(fd);
		while (str)
		{
			fill_decor(str, decor, mlx);
			free(str);
			if (check_fill(decor))
				break;
			str = get_next_line(fd);
		}
		if (!check_fill(decor))
		{
			free_decor(decor, mlx);
			decor = NULL;
		}
	}
	return (decor);
}
