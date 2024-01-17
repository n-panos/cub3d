/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:25:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/17 10:16:53 by ipanos-o         ###   ########.fr       */
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

void	ft_draw_dir(t_game *cubd, int color)
{
	int		x;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;

	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * x / WIDTH - 1;
		rayDirX = cubd->ray->dirX + cubd->ray->planeX * cameraX;
		rayDirY = cubd->ray->dirY + cubd->ray->planeY * cameraX;
		//ft_put_pixel(cubd->render, rayDirX, rayDirY, color);
		++x;
	}
}

/*void	ft_draw_dir(t_game *cubd, int color, int len)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	while (i <= len)
	{
		x = cubd->player->x + (i * cubd->ray->dir->x / 10);
		y = cubd->player->y + (i * cubd->ray->dir->y / 10);
		if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
			ft_put_pixel(cubd->render, x, y, color);
		else
			break ;
		++i;
	}
}*/

void	ft_put_pixel(t_image *image, int x, int y, int color)
{
	((int *)image->addr)[(x) + (y * image->size_line / 4)] = color;
}
