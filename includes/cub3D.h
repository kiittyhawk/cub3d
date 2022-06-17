/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:19:48 by nmordeka          #+#    #+#             */
/*   Updated: 2022/06/17 15:28:59 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>

# define SYM_WEST		'W'
# define SYM_EAST		'E'
# define SYM_SOUTH		'S'
# define SYM_NORTH		'N'
# define SYM_WALL		'1'
# define SYM_EMPTY		'0'
# define SYM_SPACE		' '

# define SCALE			16 // масштаб 2д карты

# define KEY_DOWN		65362
# define KEY_UP			65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

# define KEY_LVIEW		123
# define KEY_RVIEW		124

# define KEY_ESC		65307

# define WIN_W			1024
# define WIN_H			768

# define LINUX			1

typedef struct s_point
{
	size_t	x;
	size_t	y;
}	t_point;

typedef struct s_rect
{
	t_point	base;
	size_t	w;
	size_t	h;
}	t_rect;

typedef struct s_sprite
{
	int		w;
	int		h;
	void	*img_data;
}	t_sprite;

typedef struct s_decor
{
	t_sprite	*south;
	t_sprite	*north;
	t_sprite	*east;
	t_sprite	*west;
	int			ceiling;
	int			floor;
}	t_decor;

typedef struct	s_ray //структура для игрока и луча
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	int			hit;
	double		perpwalldist;
	double		camX;
	int			rx;
	int			ry;
	int			dx;
	int			dy;
	int			x;
	int			mapX;
	int			mapY;
	double		moveSpeed;
	double		rotSpeed;
	double		raydirX;
	double		raydirY;
	double		deltadistX;
	double		deltadistY;
	int			stepX;
	int			stepY;
	double		sidedistX;
	double		sidedistY;
	int			side;
	int			drawStart;
	int			drawEnd;
	int			lineHeight;
}				  t_ray;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	char		*addr;
	void		*img;
	int			bpp;
	int			en;	
	int			line_l;
}	t_mlx;


typedef struct s_game
{
	t_ray		ray;
	t_mlx		mlx;
	char		point_view;
	int			width;
	int			height;
	int			win_w;
	int			win_h;
	t_decor		*decor;	
	char		**map;
	int			color;
	
}	t_game;

int			ft_pars_color(char	*str);
void		free_decor(t_decor *decor, void *mlx);
t_decor		*read_decor(int fd, void *mlx);

t_sprite	*ft_sprite_init(char *str, void *mlx);
void		ft_free_sprite(t_sprite *sprite, void *mlx);

void		read_map(t_game *game, int fd);
char		*check_map(t_game *game);

t_game		*game_init(int fd);
void		game_exit(t_game *game, char *err_mess, int code, int fd);
int			player_move(int key, t_game *game);
int			draw_buffer(t_game	*game);

int			str_empty(char *str);

#endif