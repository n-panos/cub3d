/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:15 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/09 13:09:49 by ipanos-o         ###   ########.fr       */
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
	game->player = ft_pos_init(map->spawn->x, map->spawn->y);
	if (map->spawn_orient == 'N')
		game->ray = ft_pos_init(0, -1);
	else if (map->spawn_orient == 'S')
		game->ray = ft_pos_init(0, 1);
	else if (map->spawn_orient == 'E')
		game->ray = ft_pos_init(1, 0);
	else if (map->spawn_orient == 'W')
		game->ray = ft_pos_init(-1, 0);
	return (game);
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
