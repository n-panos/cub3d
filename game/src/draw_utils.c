/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:25:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/31 13:26:06 by ipanos-o         ###   ########.fr       */
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
		ft_calculos(cubd, ray, rayDirX, rayDirY);
		ft_draw_vertical(cubd, ray->drawStart, ray->drawEnd, x);
		++x;
	}
}

void	ft_calculos(t_game *cubd, t_ray *ray, \
		double rayDirX, double rayDirY)
{
	int	i;

	if (rayDirX == 0)
		ray->deltaDistX = MAXFLOAT;
	else
		ray->deltaDistX = fabs(1 / rayDirX);
	if (rayDirY == 0)
		ray->deltaDistY = MAXFLOAT;
	else
		ray->deltaDistY = fabs(1 / rayDirY);
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
		if (cubd->map->map[ray->map->y][ray->map->x] == '1')
			ray->hit = 1;
	}
	//euclidean distance calculus
	if (ray->side == 0)
		ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
	else
		ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
	//calculate wall height
	ray->lineHeight = abs((int)(HEIGHT / ray->perpWallDist));
	ray->drawStart = -ray->lineHeight / 2 + HEIGHT / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + HEIGHT / 2;
	if (ray->drawEnd >= HEIGHT)
		ray->drawEnd = HEIGHT - 1;
	//texturing calc
	ray->texNum = cubd->map->map[ray->map->y][ray->map->x] - 1;
	if (ray->side == 0)
		ray->wallX = ray->posY + ray->perpWallDist * ray->dirY;
	else
		ray->wallX = ray->posX + ray->perpWallDist * ray->dirX;
	ray->wallX -= floor(ray->wallX);
	ray->texX = ray->wallX * ray->texwidth;
	if (ray->side == 0 && ray->dirX > 0)
		ray->texX = ray->texwidth - ray->texX - 1;
	if (ray->side == 1 && ray->dirY < 0)
		ray->texX = ray->texwidth - ray->texX - 1;
	//height of texture
	ray->steps = 1.0 * ray->texwidth / ray->lineHeight;
	ray->texPos = (ray->drawStart - HEIGHT / 2 + ray->lineHeight / 2) * ray->steps;
	i = ray->drawStart;
	while (i < ray->drawEnd)
	{
		ray->texY = (int)ray->texPos & (ray->texwidth - 1);
		ray->texPos += ray->steps;
		++i;
	}
}

void	ft_draw_vertical(t_game *cubd, int drawStart, int drawEnd, int x)
{
	int	y;

	y = HEIGHT;
	while (y > 0)
	{
		//cubd->ray->color = cubd->ray->texture->addr[(cubd->ray->texX) + (cubd->ray->texY * cubd->render->size_line / 4)];
		if (y < drawStart)
			ft_put_pixel(cubd->render, x, y, YELLOW);
		//if (y == drawStart || y == drawEnd)
		//	ft_put_pixel(cubd->render, x, y, BLACK);
		if (y > drawStart && y < drawEnd)
			ft_put_pixel(cubd->render, x, y, cubd->ray->color);
		--y;
	}
}

t_image	*ft_png_to_image(t_game *cubd)
{
	char	*dir;
	t_image	*texture;

	dir = cubd->map->north_path;
	texture = malloc(sizeof(t_image));
	texture->ptr = mlx_new_image(cubd->mlx, cubd->ray->texwidth, cubd->ray->texheight);
	texture->addr = (int *)mlx_get_data_addr(texture->ptr, &texture->bits, \
	&texture->size_line, &texture->endian);
	texture->ptr = mlx_xpm_file_to_image(cubd->mlx, dir, \
	&cubd->ray->texwidth, &cubd->ray->texheight);
	return (texture);
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
