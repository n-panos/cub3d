/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:03 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/09 13:14:55 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_game(t_map *map)
{
	t_game	*cubd;

	cubd = ft_init_game(map);
	ft_minimap(cubd);
	mlx_hook(cubd->window, 2, 1L << 0, ft_keys, cubd);
	mlx_hook(cubd->window, 17, 1L << 2, ft_end_game, cubd);
	mlx_loop(cubd->mlx);
	return (0);
}

int	ft_keys(int key_code, t_game *game)
{
	if (key_code == ESC)
		ft_end_game(game);
	else if (key_code == W || key_code == UP)
		ft_move(game, UP);
	else if (key_code == S || key_code == DOWN)
		ft_move(game, DOWN);
	else if (key_code == A || key_code == LEFT)
		ft_move(game, LEFT);
	else if (key_code == D || key_code == RIGHT)
		ft_move(game, RIGHT);
	return (0);
}
