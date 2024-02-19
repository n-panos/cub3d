/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:15 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/02/08 13:28:41 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*ft_init_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->map = map;
	game->render = ft_generate_image(game, WIDTH, HEIGHT);
	game->textures = malloc(sizeof(t_text));
	game->textures->n = ft_png_to_image(game, game->map->north_path);
	game->textures->s = ft_png_to_image(game, game->map->south_path);
	game->textures->e = ft_png_to_image(game, game->map->east_path);
	game->textures->w = ft_png_to_image(game, game->map->west_path);
	game->player = malloc (sizeof(t_play));
	game->player->move_speed = 0.5;
	game->player->turn_speed = 0.3;
	game->player->pos.x = game->map->spawn->x;
	game->player->pos.y = game->map->spawn->y;
	return (game);
}

t_image	*ft_generate_image(t_game *cubd, int width, int height)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	image->ptr = mlx_new_image(cubd->mlx, width, height);
	image->width = width;
	image->height = height;
	image->addr = (int *)mlx_get_data_addr(image->ptr, &image->bits, \
	&image->size_line, &image->endian);
	return (image);
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
