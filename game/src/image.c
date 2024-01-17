/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/17 09:14:20 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_minimap(t_game *cubd)
{
	ft_draw_map(cubd);
	ft_draw_player(cubd, GREEN);
	ft_draw_dir(cubd, YELLOW);
	ft_cuadriculas(cubd, 0, 0);
	mlx_put_image_to_window(cubd->mlx, cubd->window, cubd->render->ptr, 0, 0);
}

void	ft_draw_map(t_game *cubd)
{
	int		x;
	int		y;
	t_pos	start;
	t_pos	end;

	y = 0;
	while (cubd->map->map[y])
	{
		x = 0;
		while (cubd->map->map[y][x])
		{
			ft_give_coords(&start, x * DIST, y * DIST);
			ft_give_coords(&end, start.x + DIST, start.y + DIST);
			if (cubd->map->map[y][x] == '0' || cubd->map->map[y][x] == 'p')
				ft_draw_rect(cubd, start, end, GREY);
			if (cubd->map->map[y][x] == '1')
				ft_draw_rect(cubd, start, end, MAGENTA);
			++x;
		}
		++y;
	}
}

void	ft_draw_player(t_game *cubd, int color)
{
	t_pos	player;
	t_pos	start;
	t_pos	end;

	ft_give_coords(&player, cubd->player->x, cubd->player->y);
	ft_give_coords(&start, player.x - 3, player.y - 3);
	ft_give_coords(&end, player.x + 3, player.y + 3);
	ft_draw_rect(cubd, start, end, color);
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
			ft_put_pixel(cubd->render, x, y, WHITE);
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
			ft_put_pixel(cubd->render, x, y, WHITE);
			x = x + 1;
		}
		y = y + DIST;
	}
}
