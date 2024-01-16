/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:06:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/16 13:24:12 by nacho            ###   ########.fr       */
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
		x = cubd->player->x + floor(moves * cubd->ray->dir->x);
		y = cubd->player->y + floor(moves * cubd->ray->dir->y);
	}
	else
	{
		x = cubd->player->x + floor(moves * cubd->ray->dir->y);
		y = cubd->player->y + floor(moves * cubd->ray->dir->x);
	}
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		ft_give_coords(cubd->player, x, y);
}

void	ft_turn(t_game *cubd, int dir)
{
	if (dir == LEFT)
		cubd->ray->p_angle -= TURN;
	else if (dir == RIGHT)
		cubd->ray->p_angle += TURN;
	if (cubd->ray->p_angle < 0)
		cubd->ray->p_angle += 2 * PI;
	else if (cubd->ray->p_angle > 2 * PI)
		cubd->ray->p_angle -= 2 * PI;
	ft_give_coords(cubd->ray->dir, cos(cubd->ray->p_angle) * 10, \
	sin(cubd->ray->p_angle) * 10);
}
