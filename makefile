OS	= $(shell uname)
NAME		= cub3d

SRC_PATH	= ./src
LIBFT_PATH	= ./libft
INCLUDES	= ./includes
ifeq ($(OS), Linux)
	MLX_PATH	= mlx_linux
	MLX_LNK		= -L ${MLX_PATH} -lmlx -lXext -lX11 -lbsd -lm
else
	MLX_PATH	= 
	MLX_LNK		= -lmlx -framework OpenGL -framework Appkit
endif

SRC		= $(SRC_PATH)/decor.c $(SRC_PATH)/game_draw.c $(SRC_PATH)/game_exit.c \
		$(SRC_PATH)/game_move.c $(SRC_PATH)/game.c $(SRC_PATH)/main.c $(SRC_PATH)/pars_color.c \
		$(SRC_PATH)/sprite_tools.c $(SRC_PATH)/pars_map.c $(SRC_PATH)/buffer.c $(SRC_PATH)/check_map.c \
		$(SRC_PATH)/dda.c $(SRC_PATH)/player.c $(SRC_PATH)/check_map_utils.c

# SRC		= $(SRC_PATH)/main.c
HEADER	= $(INCLUDES)/cub3D.h
MLX_HEADER	= $(MLX_PATH)/mlx.h
OBJS	= $(SRC:.c=.o)

LIBFT	= $(LIBFT_PATH)/libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3 -O3 -g

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I $(INCLUDES) -I $(LIBFT_PATH) -I $(MLX_PATH)

all: libft mlx $(NAME)

mlx:
	make -C $(MLX_PATH)

libft:	$(LIBFT_PATH)/libft.h
	make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_PATH) -I $(MLX_PATH) $(OBJS) -L libft/ -lft ${MLX_LNK} -o $(NAME)

clean: 
	rm -f ${OBJS}

fclean: clean
	make fclean -C libft
	make clean -C $(MLX_PATH)
	rm -f ${NAME}

re: fclean all


.PHONY: all clean fclean re mlx libft