#include "cub3d.h"

int ft_game(t_map *map)
{
	t_game	*cubd;

	cubd = ft_init_game(map);
	ft_draw_map(cubd);
	mlx_key_hook(cubd->window, ft_keys, cubd);
	mlx_hook(cubd->window, 17, 1L << 2, ft_end_game, cubd);
	mlx_loop(cubd->mlx);
	return (0);
}

int	ft_keys(int key_code, t_game *game)
{
	if (key_code == ESC)
		ft_end_game(game);
	/*else if (key_code == W || key_code == UP)
		ft_move();
	else if (key_code == S || key_code == DOWN)
		ft_move();
	else if (key_code == A || key_code == LEFT)
		ft_move();
	else if (key_code == D || key_code == RIGHT)
		ft_move();*/
	return (0);
}
