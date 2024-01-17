/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:12:24 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/17 10:34:49 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_end_game(t_game *game)
{
	ft_free_ray(game->ray);
	ft_free_image(game->render, game->mlx);
	ft_free_map(game->map);
	free(game->player);
	mlx_destroy_window(game->mlx, game->window);
	free(game);
	ft_putstr_fd("\nEnding Game\n", 1);
	exit(EXIT_SUCCESS);
}

void	ft_free_map(t_map *map)
{
	ft_mtx_free(map->map);
	map->map = NULL;
	free(map->north_path);
	map->north_path = NULL;
	free(map->south_path);
	map->south_path = NULL;
	free(map->west_path);
	map->west_path = NULL;
	free(map->east_path);
	map->east_path = NULL;
	free(map->spawn);
	free(map->ceiling);
	free(map->floor);
	free(map);
}

void	ft_free_ray(t_ray *ray)
{
	free(ray->map);
	free(ray->step);
	free(ray);
}

void	ft_free_image(t_image *image, void *mlx)
{
	mlx_destroy_image(mlx, image->ptr);
	free(image);
}
