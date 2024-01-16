/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:15 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/16 16:45:39 by nacho            ###   ########.fr       */
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
	game->ray = ft_init_ray(map->spawn, map->spawn_orient);
	game->time = 0;
	game->old_time = 0;
	return (game);
}

t_ray	*ft_init_ray(t_pos *player, char c)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (c == 'N')
		ray->p_angle = PI * 3 / 2;
	else if (c == 'S')
		ray->p_angle = PI / 2;
	else if (c == 'E')
		ray->p_angle = 0;
	else if (c == 'W')
		ray->p_angle = PI;
	ray->dir = ft_pos_init(cos(ray->p_angle), sin(ray->p_angle));
	ray->map = ft_pos_init(player->x, player->y);
	ray->plane = ft_pos_init(0, 0.66);
	return (ray);
}

t_image	*ft_generate_image(t_game *cubd, int width, int height)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	image->ptr = mlx_new_image(cubd->mlx, width, height);
	image->width = width;
	image->height = height;
	image->addr = mlx_get_data_addr(image->ptr, &image->bits, &image->size_line, &image->endian);
	return image;
}
