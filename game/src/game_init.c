/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:15 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/17 09:44:31 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*ft_init_game(t_map *map)
{
	t_game	*game;
	int		half;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->map = map;
	game->render = ft_generate_image(game, WIDTH, HEIGHT);
	half = floor(DIST / 2);
	game->player = ft_pos_init(map->spawn->x * DIST + half, \
	map->spawn->y * DIST + half);
	game->ray = ft_init_ray(game->player, map->spawn_orient);
	game->ray->map = ft_pos_init(map->spawn->x, map->spawn->y);
	return (game);
}

t_ray	*ft_init_ray(t_pos *player, char c)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->posX = player->x;
	ray->posY = player->y;
	ray = ft_start_dir(ray, c);
	ray->planeX = 0;
	ray->planeY = 0.66;
	ray->time = 0;
	ray->oldtime = 0;
	return (ray);
}

t_ray	*ft_start_dir(t_ray *ray, char c)
{
	if (c == 'N')
	{
		ray->dirX = 0;
		ray->dirY = -1;
	}
	else if (c == 'S')
	{
		ray->dirX = 0;
		ray->dirY = 1;
	}
	else if (c == 'E')
	{
		ray->dirX = 1;
		ray->dirY = 0;
	}
	else if (c == 'W')
	{
		ray->dirX = -1;
		ray->dirY = 0;
	}
	return (ray);
}

t_image	*ft_generate_image(t_game *cubd, int width, int height)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	image->ptr = mlx_new_image(cubd->mlx, width, height);
	image->width = width;
	image->height = height;
	image->addr = mlx_get_data_addr(image->ptr, &image->bits, \
	&image->size_line, &image->endian);
	return (image);
}
