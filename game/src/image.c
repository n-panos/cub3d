/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/09 10:34:30 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	player = ft_pos_init(cubd->player->x * DIST, cubd->player->y * DIST);
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
