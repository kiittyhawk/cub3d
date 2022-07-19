/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:19:48 by nmordeka          #+#    #+#             */
/*   Updated: 2022/07/19 12:26:45 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>

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

# define ANGLE			0.66

# define MOVE_SPEED		0.15
# define ROT_SPEED		0.06

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_rect
{
	t_point	base;
	int		w;
	int		h;
}	t_rect;

typedef struct s_buffer
{
	void	*data;
	char	*addr;
	int		w;
	int		h;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
}	t_buffer;

typedef struct s_decor
{
	t_buffer	*south;
	t_buffer	*north;
	t_buffer	*east;
	t_buffer	*west;
	int			ceiling;
	int			floor;
}	t_decor;

typedef struct s_camera
{
	double	angle_view;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_camera;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	double	ray_dirx;
	double	ray_diry;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	dist_perpw;
	double	step;
	int		texx;
	int		texy;
	double	tex_pos;
}	t_dda;

typedef struct s_game
{
	int			x;
	int			y;
	t_camera	*camera;
	int			width;
	int			height;
	t_buffer	*buffer;
	t_dda		*dda;
	void		*mlx;
	void		*win;
	t_decor		*decor;
	char		**map;
}	t_game;

int				ft_pars_color(char	*str);
void			free_decor(t_decor *decor, void *mlx);
int				read_decor(t_decor *decor, int fd, void *mlx);

t_buffer		*init_buf(void *mlx, int width, int height, char *path);
void			free_buffer(t_buffer *buffer, void *mlx);

void			fill_player(t_game *game);
void			read_map(t_game *game, int fd);
int				check_map(t_game *game);

t_game			*game_init(int fd);
void			game_exit(t_game *game, char *err_mess, int code, int fd);
int				player_move(int key, t_game *game);

unsigned int	buf_get_pixel(t_buffer *buff, int x, int y);
void			buf_put_pixel(t_buffer *buffer, int x, int y, int color);
void			buf_clear(t_buffer *buffer, int color);
void			buf_fill_rect(t_buffer *buffer, t_rect rect, int color);
t_buffer		*init_buf(void *mlx, int width, int height, char *path);
void			free_buffer(t_buffer *buffer, void *mlx);

void			draw_vert_tex(int x, int length, t_buffer *text, t_game *game);

void			draw_line(int x, int length, char view, t_game *game);
int				draw_buffer(t_game	*game);

void			print_line(int x, t_game *game);

t_camera		*camera_init(int x, int y, char view);
int				str_empty(char *str);

int				is_inside_walls_y(char **map, int x, int y, t_game *game);
int				is_inside_walls_x(char **map, int x, int y, t_game *game);
int				check_char(char *targ, char *str);
int				print_message(char *str);
void			fill_zero_all(t_game *game);

#endif