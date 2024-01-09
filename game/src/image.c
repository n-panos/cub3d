#include "cub3d.h"

void	ft_draw_map(t_game *cubd)
{
	ft_minimap(cubd);
}

void	ft_minimap(t_game *cubd)
{
	ft_draw_player(cubd);
	ft_cuadriculas(cubd, 0, 0);
}

void	ft_draw_player(t_game *cubd)
{
	t_pos	*player;

	//player = ft_pos_init(((WIDTH - MAP_W) / 2) + MAP_W, \
	((HEIGHT - MAP_H) / 2) + MAP_H);
	player = ft_pos_init(cubd->player->x * MULTI, cubd->player->y * MULTI);
	mlx_pixel_put(cubd->mlx, cubd->window, player->x, player->y, RED);
}

void	ft_cuadriculas(t_game *cubd, int x_init, int y_init)
{
	int	x;
	int	y;

	x = x_init;
	while (x < WIDTH)
	{
		y = y_init;
		while (y < HEIGHT)
		{
			mlx_pixel_put(cubd->mlx, cubd->window, x, y, RED);
			y = y + 1;
		}
		x = x + 10;
	}
	y = y_init;
	while (y < HEIGHT)
	{
		x = x_init;
		while (x < WIDTH)
		{
			mlx_pixel_put(cubd->mlx, cubd->window, x, y, RED);
			x = x + 1;
		}
		y = y + 10;
	}
}
