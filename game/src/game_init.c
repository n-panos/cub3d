/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:15 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/11 12:16:03 by ipanos-o         ###   ########.fr       */
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
	//ft_put_pixel(game->render, 10, 10, RED);
	//mlx_put_image_to_window(game->mlx, game->window, game->render->ptr, 0, 0);
	half = floor(DIST / 2);
	game->player = ft_pos_init(map->spawn->x * DIST + half, \
	map->spawn->y * DIST + half);
	if (map->spawn_orient == 'N')
		game->p_angle = PI * 3 / 2;
	else if (map->spawn_orient == 'S')
		game->p_angle = PI / 2;
	else if (map->spawn_orient == 'E')
		game->p_angle = 0;
	else if (map->spawn_orient == 'W')
		game->p_angle = PI;
	game->ray = ft_pos_init(cos(game->p_angle) * 10, sin(game->p_angle) * 10);
	return (game);
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


void ft_put_pixel(t_image *image, int x, int y, int color)
{
	((int *)image->addr)[(x) + (y * image->size_line / 4)] = color;
}

int	ft_end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free(game->ray);
	free(game->player);
	ft_free_map(game->map);
	free(game);
	ft_putstr_fd("\nEnding Game\n", 1);
	exit(EXIT_SUCCESS);
}
