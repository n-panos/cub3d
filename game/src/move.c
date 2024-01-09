/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:06:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/09 11:42:00 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_front_back(t_game *cubd, int dir)
{
	double	moves;
	int		x;
	int		y;

	if (dir == UP || dir == RIGHT)
		moves = 5;
	else if (dir == DOWN || dir == LEFT)
		moves = -5;
	if (dir == UP || dir == DOWN)
	{
		x = cubd->player->x + floor(moves * cubd->ray->x);
		y = cubd->player->y + floor(moves * cubd->ray->y);
	}
	else
	{
		x = cubd->player->x + floor(moves * cubd->ray->y);
		y = cubd->player->y + floor(moves * cubd->ray->x);
	}
	ft_draw_player(cubd, BLACK);
	ft_give_coords(cubd->player, x, y);
	ft_draw_player(cubd, GREEN);
}

void	ft_move_back(t_game *cubd)
{
}

void	ft_move_left(t_game *cubd)
{
}

void	ft_move_right(t_game *cubd)
{
}
