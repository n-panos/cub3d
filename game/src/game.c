/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:03 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/02/07 15:53:07 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_game(t_map *map)
{
	t_game	*cubd;

	cubd = ft_init_game(map);
	ft_render(cubd);
	//ft_minimap(cubd);
	mlx_hook(cubd->window, 2, 1L << 0, ft_keys, cubd);
	mlx_hook(cubd->window, 17, 1L << 2, ft_end_game, cubd);
	mlx_loop(cubd->mlx);
	return (0);
}

int	ft_keys(int key_code, t_game *game)
{
	if (key_code == ESC)
		ft_end_game(game);
	else if (key_code == W)
		ft_move_up(game->player, game->map->map);
	else if (key_code == S)
		ft_move_down(game->player, game->map->map);
	else if (key_code == A)
		ft_move_left(game->player, game->map->map);
	else if (key_code == D)
		ft_move_right(game->player, game->map->map);
	else if (key_code == LEFT)
		ft_turn_left(game, game->player->turn_speed);
	else if (key_code == RIGHT)
		ft_turn_right(game, game->player->turn_speed);
	ft_render(game);
	return (0);
}

void	ft_render(t_game *cubd)
{
	ft_raycasting(cubd);
	mlx_put_image_to_window(cubd->mlx, cubd->window, cubd->render->ptr, 0, 0);
}
