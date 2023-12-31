/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:25:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/09 13:25:24 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_rect(t_game *cubd, t_pos start, t_pos end, int color)
{
	int	x;
	int	y;

	x = start.x;
	while (x <= end.x)
	{
		y = start.y;
		while (y <= end.y)
		{
			mlx_pixel_put(cubd->mlx, cubd->window, x, y, color);
			++y;
		}
		++x;
	}
}

void	ft_draw_cuadricula(t_game *cubd, t_pos start)
{
	int	x;
	int	y;

	x = start.x;
	while (x <= start.x + DIST)
	{
		mlx_pixel_put(cubd->mlx, cubd->window, x, start.y, GREEN);
		mlx_pixel_put(cubd->mlx, cubd->window, x, start.y + DIST, GREEN);
		++x;
	}
}
