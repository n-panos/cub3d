/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:06:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/09 12:53:45 by ipanos-o         ###   ########.fr       */
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
		x = cubd->player->x + floor(moves * cubd->ray->x);
		y = cubd->player->y + floor(moves * cubd->ray->y);
	}
	else
	{
		x = cubd->player->x + floor(moves * cubd->ray->y);
		y = cubd->player->y + floor(moves * cubd->ray->x);
	}
	ft_draw_player(cubd, BLACK);
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		ft_give_coords(cubd->player, x, y);
	ft_draw_player(cubd, GREEN);
}
