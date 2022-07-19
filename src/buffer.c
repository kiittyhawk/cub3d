/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmordeka <nmordeka@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 00:18:10 by nmordeka          #+#    #+#             */
/*   Updated: 2022/07/11 18:47:14 by nmordeka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	buf_put_pixel(t_buffer *buffer, int x, int y, int color)
{
	char	*dest;

	dest = buffer->addr + (y * buffer->size_line + x * \
		(buffer->bits_per_pixel / 8));
	*(unsigned int *) dest = color;
}

unsigned int	buf_get_pixel(t_buffer *buff, int x, int y)
{
	unsigned int	color;
	char			*dest;

	dest = buff->addr + (y * buff->size_line + x * (buff->bits_per_pixel / 8));
	color = *(unsigned int *) dest;
	return (color);
}

void	buf_clear(t_buffer *buffer, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < buffer->h)
	{
		x = -1;
		while (++x < buffer->w)
			buf_put_pixel(buffer, x, y, color);
	}
}

void	buf_fill_rect(t_buffer *buffer, t_rect rect, int color)
{
	int	x;
	int	y;

	if (rect.base.x < 0)
		rect.base.x = 0;
	if (rect.base.y < 0)
		rect.base.y = 0;
	if (rect.w >= buffer->w)
		rect.w = buffer->w;
	if (rect.h >= buffer->h)
		rect.h = buffer->h;
	y = rect.base.y - 1;
	while (++y < (rect.base.y + rect.h))
	{
		x = rect.base.x - 1;
		while (++x < (rect.base.x + rect.w))
			buf_put_pixel(buffer, x, y, color);
	}
}
