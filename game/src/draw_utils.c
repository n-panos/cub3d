/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:25:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/10 13:41:54 by nacho            ###   ########.fr       */
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

void	ft_draw_dir(t_game *cubd, int color)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	while (i <= 20)
	{
		x = cubd->player->x + (i * cubd->ray->x);
		y = cubd->player->y + (i * cubd->ray->y);
		mlx_pixel_put(cubd->mlx, cubd->window, x, y, color);
		++i;
	}
}
