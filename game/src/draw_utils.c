/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:25:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/11 12:20:48 by ipanos-o         ###   ########.fr       */
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
			ft_put_pixel(cubd->render, x, y, color);
			++y;
		}
		++x;
	}
}

void	ft_draw_dir(t_game *cubd, int color, int len)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	while (i <= len)
	{
		x = cubd->player->x + (i * cubd->ray->x / 10);
		y = cubd->player->y + (i * cubd->ray->y / 10);
		ft_put_pixel(cubd->render, x, y, color);
		++i;
	}
}
