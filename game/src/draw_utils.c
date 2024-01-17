/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:25:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/17 13:05:04 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw(t_game *cubd, t_ray *ray)
{
	int		x;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;

	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * x / WIDTH - 1;
		rayDirX = ray->dirX + ray->planeX * cameraX;
		rayDirY = ray->dirY + ray->planeY * cameraX;
		ft_draw_calculos(cubd, ray, rayDirX, rayDirY);
		ft_draw_vertical(cubd, ray->drawStart, ray->drawEnd, x);
		++x;
	}
}

void	ft_draw_calculos(t_game *cubd, t_ray *ray, double rayDirX, double rayDirY)
{
	if (rayDirX == 0)
		rayDirX = MAXFLOAT;
	if (rayDirY == 0)
		rayDirY = MAXFLOAT;
	ray->deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
	ray->deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
	if (rayDirX < 0)
	{
		ray->step->x = -1;
		ray->sideDistX = (ray->posX - ray->map->x) * ray->deltaDistX;
	}
	else
	{
		ray->step->x = 1;
		ray->sideDistX = (ray->map->x + 1 - ray->posX) * ray->deltaDistX;
	}
	if (rayDirY < 0)
	{
		ray->step->y = -1;
		ray->sideDistY = (ray->posY - ray->map->y) * ray->deltaDistY;
	}
	else
	{
		ray->step->y = 1;
		ray->sideDistY = (ray->map->y + 1 - ray->posY) * ray->deltaDistY;
	}
	//DDA
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->map->x += ray->step->x;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->map->y += ray->step->y;
			ray->side = 1;
		}
		if (cubd->map->map[ray->map->x][ray->map->y] == '1')
			ray->hit = 1;
	}
	//euclidean distance calculus
	if (ray->side == 0)
	{
		ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
		ray->color = GREEN;
	}
	else
	{
		ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
		ray->color = BLUE;
	}
	//calculate wall height
	ray->lineHeight = HEIGHT / ray->perpWallDist;
	ray->drawStart = -ray->lineHeight / 2 + HEIGHT / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + HEIGHT / 2;
	if (ray->drawEnd > HEIGHT)
		ray->drawEnd = HEIGHT - 1;
}

void	ft_draw_vertical(t_game *cubd, int drawStart, int drawEnd, int x)
{
	int	y;

	y = HEIGHT;
	while (y > 0)
	{
		if (y > drawStart)
			ft_put_pixel(cubd->render, x, y, YELLOW);
		if (y == drawStart || y == drawEnd)
			ft_put_pixel(cubd->render, x, y, BLACK);
		if (y < drawStart && y > drawEnd)
			ft_put_pixel(cubd->render, x, y, CYAN);
		--y;
	}
}

void	ft_put_pixel(t_image *image, int x, int y, int color)
{
	((int *)image->addr)[(x) + (y * image->size_line / 4)] = color;
}


void	ft_draw_dir(t_game *cubd, int color, int len)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	while (i <= len)
	{
		x = cubd->player->x + (i * cubd->ray->dirX / 10);
		y = cubd->player->y + (i * cubd->ray->dirY / 10);
		if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
			ft_put_pixel(cubd->render, x, y, color);
		else
			break ;
		++i;
	}
}

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
