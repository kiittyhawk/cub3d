/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmordeka <nmordeka@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:17:10 by nmordeka          #+#    #+#             */
/*   Updated: 2022/05/16 00:06:37 by nmordeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_sprite(t_sprite *sprite, void *mlx)
{
	if (!sprite)
		return ;
	if (sprite->img_data)
		mlx_destroy_image(mlx, sprite->img_data);
	free(sprite);
}

t_sprite	*ft_sprite_init(char *path, void *mlx)
{
	t_sprite	*spr;
	int			i;
	int			j;

	i = 0;
	while (path[i] != '\0' && path[i] == ' ')
		++i;
	j = i;
	while (path[j] != '\0' && path[j] != ' ' && path[j] != '\n')
		++j;
	if (path[j] != '\0')
		path[j] = '\0';
	spr = malloc(sizeof(t_sprite));
	if (!spr)
		return (NULL);
	spr->img_data = mlx_xpm_file_to_image(mlx, &path[i], &spr->w, &spr->h);
	if (!(spr->img_data))
	{
		free(spr);
		spr = NULL;
	}
	return (spr);
}
