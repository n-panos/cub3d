#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>

# include "../parser/header/parser.h"
# include "libft/includes/libft.h"

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct  s_map
{
    char    **map;
    char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
    int     floor_rgb[3];
    int     ceiling_rgb[3];
	char	spawn_orient;
	t_pos	*spawn;
}           t_map;

typedef struct s_game
{
	t_map	*map;
	void	*mlx;
	void	*window;
	t_pos	*player;
}			t_game;

typedef struct s_img
{
	int		width;
	int		height;
}			t_img;


#endif