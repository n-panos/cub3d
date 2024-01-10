/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:15 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/10 13:40:47 by nacho            ###   ########.fr       */
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
	game->ray = ft_pos_init(cos(game->p_angle) * 2, sin(game->p_angle) * 2);
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
