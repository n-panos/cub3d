/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:04:30 by nacho             #+#    #+#             */
/*   Updated: 2024/02/08 13:12:06 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycasting(t_game *cubd)
{
	int			x;
	t_ray	    ray;
	t_line		line;
	t_play  	*player;

	x = 0;
	player = cubd->player;
	mlx_clear_window(cubd->mlx, cubd->window);
	while (x < WIDTH)
	{
		ft_set_pos(player, &ray, x);
		line.wall_tex = ft_dda(cubd, &ray);
		ft_walldist(&ray);
		ft_v_line(&line, &ray);
		ft_texture(cubd, &line, &ray);
		ft_paint_pixels(cubd, &line, &ray, x);
        ++x;
	}
}

void	ft_set_pos(t_play *p, t_ray *ray, int x)
{
	ray->mpos.x = (int)p->pos.x;
	ray->mpos.y = (int)p->pos.y;
	ray->hit = 0;
	ft_raydir_and_dist(ray, p, x);
	ft_step(ray, p);
}

void	ft_raydir_and_dist(t_ray *ray, t_play *p, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir.x = p->dir.x + p->plane.x * ray->camera_x;
	ray->ray_dir.y = p->dir.y + p->plane.y * ray->camera_x;
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = MAXFLOAT;
	else
		ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta_dist.y = MAXFLOAT;
	else
		ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
}

void	ft_step(t_ray *ray, t_play *p)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (p->pos.x - ray->mpos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->mpos.x + 1.0 - p->pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (p->pos.y - ray->mpos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->mpos.y + 1.0 - p->pos.y) * ray->delta_dist.y;
	}
}

//      DDA page

char	ft_dda(t_game *cubd, t_ray *ray)
{
	char	**map;
	char	wall;

	map = cubd->map->map;
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->mpos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->mpos.y += ray->step.y;
			ray->side = 1;
		}
		wall = ft_what_tex(ray);
		if (map[(int)ray->mpos.y][(int)ray->mpos.x] == '1')
			ray->hit = 1;
	}
	return (wall);
}

char	ft_what_tex(t_ray *ray)
{
	char	wall_tex;

	if (ray->ray_dir.x < 0 && ray->side == 0)
		wall_tex = 'W';
	else if (ray->ray_dir.x > 0 && ray->side == 0)
		wall_tex = 'E';
	else if (ray->ray_dir.y < 0 && ray->side == 1)
		wall_tex = 'N';
	else
		wall_tex = 'S';
	return (wall_tex);
}

//      Wall dist page

void	ft_walldist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
}

void	ft_v_line(t_line *line, t_ray *ray)
{
	line->line_height = abs((int)(HEIGHT / ray->perp_wall_dist));
	line->draw_start = -line->line_height / 2 + HEIGHT / 2;
	if (line->draw_start < 0)
		line->draw_start = 0;
	line->draw_end = line->line_height / 2 + HEIGHT / 2;
	if (line->draw_end >= HEIGHT)
		line->draw_end = HEIGHT - 1;
}

void	ft_texture(t_game *cubd, t_line *line, t_ray *ray)
{
	t_play	*p;
	t_image	*texture;

	p = cubd->player;
	if (ray->side == 0)
		ray->wall_x = p->pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		ray->wall_x = p->pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	ray->wall_x -= floor(ray->wall_x);
	texture = ft_get_texture(line, cubd, ray);
	line->tex_x = (int)(ray->wall_x * (double)texture->width);
	if (ray->side == 0 && ray->ray_dir.x > 0)
		line->tex_x = texture->width - line->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir.y < 0)
		line->tex_x = texture->width - line->tex_x - 1;
}

t_image *ft_get_texture(t_line *line, t_game *cubd, t_ray *ray)
{
	t_image *texture;

	texture = NULL;
	(void)ray;
	if (line->wall_tex == 'N')
		texture = cubd->textures->n;
	else if (line->wall_tex == 'S')
		texture = cubd->textures->s;
	else if (line->wall_tex == 'E')
		texture = cubd->textures->e;
	else if (line->wall_tex == 'W')
		texture = cubd->textures->w;
	return (texture);
}

//      dibujar el pixel 2 opciones

void	ft_put_pixel(t_image *image, int x, int y, int color)
{
	((int *)image->addr)[(x) + (y * image->size_line / 4)] = color;
}

void	my_img_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = (char *)image->addr + (y * image->size_line + x * (image->bits / 8));
	*(unsigned int *)dst = color;
}



void	ft_paint_pixels(t_game *cubd, t_line *line, t_ray *ray, int x)
{
	double	step;
	double	tex_pos;
	int		y;
	t_image	*texture;

	texture = ft_get_texture(line, cubd, ray);
	step = 1.0 * texture->height / line->line_height;
	tex_pos = (line->draw_start - HEIGHT / 2 + line->line_height / 2) * step;
	y = -1;
	ray->line = line;
	while (++y < line->draw_start)
		my_img_pixel_put(cubd->render, x, y, CYAN);
	while (y <= line->draw_end)
	{
		ray->curent_col = x;
		ray->current_row = y;
		ft_wall(cubd, ray, &step, &tex_pos);
		y++;
	}
	while (y < HEIGHT)
		my_img_pixel_put(cubd->render, x, y++, YELLOW);
}

void    ft_wall(t_game *cubd, t_ray *ray, double *step, double *tex_pos)
{
	t_image	*texture;
	int		color;

	texture = ft_get_texture(ray->line, cubd, ray);
	ray->line->tex_y = (int)(*tex_pos) & (texture->height - 1);
	(*tex_pos) += (*step);
	color = texture->addr[texture->height
		* ray->line->tex_y + ray->line->tex_x];
	my_img_pixel_put(cubd->render, ray->curent_col, ray->current_row, color);
}
