/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/09 13:30:10 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_minimap(t_game *cubd)
{
	ft_draw_player(cubd, GREEN);
	ft_draw_map();
	//ft_cuadriculas(cubd, 0, 0);
}

void	ft_draw_map(t_game *cubd)
{
	int	x;
	int	y;

	x = 0;
	while (cubd->map->map[x])
	{
		++x;
	}
}

void	ft_draw_player(t_game *cubd, int color)
{
	t_pos	*player;
	t_pos	*start;
	t_pos	*end;

	player = ft_pos_init(cubd->player->x * DIST, cubd->player->y * DIST);
	start = ft_pos_init(player->x - 1, player->y - 1);
	end = ft_pos_init(player->x + 1, player->y + 1);
	ft_draw_rect(cubd, *start, *end, color);
	free(start);
	free(end);
	free(player);
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
		x = x + DIST;
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
		y = y + DIST;
	}
}
