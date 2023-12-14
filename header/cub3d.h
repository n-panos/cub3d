#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>

//	open close etc
# include <fcntl.h>

//	perror && printf
# include <stdio.h>

//	strerror(errno)
# include <errno.h>

//	exit
# include <stdlib.h>

# include "../parser/header/parser.h"
# include "libft/includes/libft.h"
# include "mlx/mlx.h"

typedef struct s_img
{
	int		width;
	int		height;
	t_map	*map;
}			t_img;

typedef struct s_game
{
	t_img	*img;
	void	*mlx;
	void	*window;
	t_pos	*player;
}			t_game;

void	ft_exit_err(char *str);
void	ft_free_map(t_map *map);

//	testing fts

void	ft_mtx_print(char **mtx);

#endif