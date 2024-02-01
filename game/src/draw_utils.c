/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:25:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/02/01 10:01:28 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw(t_game *cubd, t_ray *ray)
{
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		ray->posX = (int)cubd->player->x;
		ray->posY = (int)cubd->player->y;
		ray->hit = 0;
		ray->cameraX = 2 * x / WIDTH - 1;
		ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
		ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
		ft_calculos(cubd, ray);
		ft_draw_vertical(cubd, x);
		++x;
	}
}

void	ft_calculos(t_game *cubd, t_ray *ray)
{
	t_image	*texture;

	t_pos pos;

	pos = *ray->map;

	if (ray->rayDirX == 0)
		ray->deltaDistX = MAXFLOAT;
	else
		ray->deltaDistX = fabs(1 / ray->rayDirX);
	if (ray->rayDirY == 0)
		ray->deltaDistY = MAXFLOAT;
	else
		ray->deltaDistY = fabs(1 / ray->rayDirY);
	if (ray->rayDirX < 0)
	{
		ray->step->x = -1;
		ray->sideDistX = (ray->posX - ray->map->x) * ray->deltaDistX;
	}
	else
	{
		ray->step->x = 1;
		ray->sideDistX = (ray->map->x + 1.0 - ray->posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->step->y = -1;
		ray->sideDistY = (ray->posY - ray->map->y) * ray->deltaDistY;
	}
	else
	{
		ray->step->y = 1;
		ray->sideDistY = (ray->map->y + 1.0 - ray->posY) * ray->deltaDistY;
	}
	//DDA
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			pos.x += ray->step->x;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			pos.y += ray->step->y;
			ray->side = 1;
		}
		ray->texpath = ft_select_texture(ray);
		if (cubd->map->map[pos.y][pos.x] == '1')
			ray->hit = 1;
	}
	//euclidean distance calculus
	if (ray->side == 0)
		ray->perpWallDist = ray->sideDistX - ray->deltaDistX;
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
	if (ray->side == 0)
		ray->wallX = ray->posY + ray->perpWallDist * ray->rayDirY;
	else
		ray->wallX = ray->posX + ray->perpWallDist * ray->rayDirX;
	ray->wallX -= floor(ray->wallX);
	texture = ft_get_texture(cubd);
	ray->texX = (int)(ray->wallX * (double)texture->width);
	if (ray->side == 0 && ray->rayDirX > 0)
		ray->texX = texture->width - ray->texX - 1;
	if (ray->side == 1 && ray->rayDirY < 0)
		ray->texX = texture->width - ray->texX - 1;
	//height of texture
	ray->steps = 1.0 * texture->height / ray->lineHeight;
	ray->texPos = (ray->drawStart - HEIGHT / 2 + ray->lineHeight / 2) * ray->steps;
}

void	ft_draw_vertical(t_game *cubd, int x)
{
	int	y;

	y = 0;
	while (y < cubd->ray->drawStart)
	{
		ft_put_pixel(cubd->render, x, y, CYAN);
		++y;
	}
	while (y <= cubd->ray->drawEnd)
	{
		cubd->ray->curr_col = x;
		cubd->ray->curr_row = y;
		ft_put_wall(cubd);
		++y;
	}
	while (y < HEIGHT)
	{
		ft_put_pixel(cubd->render, x, y, YELLOW);
		++y;
	}
}

void	ft_put_wall(t_game *cubd)
{
	int		color;
	t_image	*texture;

	texture = ft_get_texture(cubd);
	cubd->ray->texY = (int)(cubd->ray->texPos) & (texture->height - 1);
	cubd->ray->texPos += cubd->ray->steps;
	color = texture->addr[texture->height * cubd->ray->texY + cubd->ray->texX];
	ft_put_pixel(cubd->render, cubd->ray->curr_col, cubd->ray->curr_row, color);
}

t_image	*ft_png_to_image(t_game *cubd, char *dir)
{
	t_image	*texture;

	texture = malloc(sizeof(t_image));
	texture->ptr = mlx_xpm_file_to_image(cubd->mlx, dir, \
	&texture->width, &texture->height);
	texture->addr = (int *)mlx_get_data_addr(texture->ptr, &texture->bits, \
	&texture->size_line, &texture->endian);
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

char	ft_select_texture(t_ray *ray)
{
	char	tex;
	
	if (ray->rayDirX < 0 && ray->side == 0)
		tex = 'W';
	else if (ray->rayDirX > 0 && ray->side == 0)
		tex = 'E';
	else if (ray->rayDirY < 0 && ray->side == 1)
		tex = 'N';
	else
		tex = 'S';
	return (tex);
}

t_image	*ft_get_texture(t_game *cubed)
{
	t_image	*texture;

	texture = NULL;
	if (cubed->ray->texpath == 'N')
		texture = cubed->n;
	else if (cubed->ray->texpath == 'S')
		texture = cubed->s;
	else if (cubed->ray->texpath == 'E')
		texture = cubed->e;
	else if (cubed->ray->texpath == 'W')
		texture = cubed->w;
	return (texture);
}
