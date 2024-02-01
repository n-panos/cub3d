/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:06:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/02/01 12:29:03 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(t_game *cubd, int dir)
{
	double	moves;
	int		x;
	int		y;

	if (dir == UP || dir == LEFT)
		moves = SPEED;
	else if (dir == DOWN || dir == RIGHT)
		moves = -1 * SPEED;
	if (dir == UP || dir == DOWN)
	{
		x = cubd->player->x + floor(moves * cubd->ray->dirX);
		y = cubd->player->y + floor(moves * cubd->ray->dirY);
	}
	else
	{
		x = cubd->player->x + floor(moves * cubd->ray->dirY);
		y = cubd->player->y + floor(moves * cubd->ray->dirX);
	}
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		ft_give_coords(cubd->player, x, y);
}

void	ft_turn(t_game *cubd, int dir)
{
	double	dirX;
	double	planeX;
	double	turn;

	dirX = cubd->ray->dirX;
	if (dir == LEFT)
		turn = -TURN;
	else
		turn = TURN;
	cubd->ray->dirX = cubd->ray->dirX * cos(turn) - cubd->ray->dirY * sin(turn);
	cubd->ray->dirY = dirX * sin(turn) + cubd->ray->dirY * cos(turn);
	planeX = cubd->ray->planeX;
	cubd->ray->planeX = cubd->ray->planeX * cos(turn) - cubd->ray->planeY * sin(turn);
	cubd->ray->planeY = planeX * sin(turn) + cubd->ray->planeY * cos(turn);
}
