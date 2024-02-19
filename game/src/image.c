/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/02/07 15:56:15 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_minimap(t_game *cubd)
{
	ft_cuadriculas(cubd, 0, 0);
	mlx_put_image_to_window(cubd->mlx, cubd->window, cubd->render->ptr, 0, 0);
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
