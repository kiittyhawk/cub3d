/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:19:48 by nmordeka          #+#    #+#             */
/*   Updated: 2022/06/06 11:02:33 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <string.h>
# include <stdio.h>

# define SYM_WEST		'W'
# define SYM_EAST		'E'
# define SYM_SOUTH		'S'
# define SYM_NORTH		'N'
# define SYM_WALL		'1'
# define SYM_EMPTY		'0'
# define SYM_SPACE		' '

# define KEY_UP			13
# define KEY_DOWN		1
# define KEY_LEFT		0
# define KEY_RIGHT		2

# define KEY_LVIEW		123
# define KEY_RVIEW		124

# define KEY_ESC		53

# define WIN_W			1024
# define WIN_H			768

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

typedef struct s_game
{
	t_point		player;
	char		point_view;
	size_t		width;
	size_t		height;
	void		*mlx;
	void		*win;
	t_decor		*decor;	
	char		**map;
}	t_game;

int			ft_pars_color(char	*str);
void		free_decor(t_decor *decor, void *mlx);
t_decor		*read_decor(int fd, void *mlx);

t_sprite	*ft_sprite_init(char *str, void *mlx);
void		ft_free_sprite(t_sprite *sprite, void *mlx);

char		**read_map(int fd);
char		*check_map(char **map);

t_game		*game_init(int fd);
void		game_exit(t_game *game, char *err_mess, int code, int fd);
int			player_move(int key, t_game *game);
int			draw_buffer(t_game	*game);

#endif