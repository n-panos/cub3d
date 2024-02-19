/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:06:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/02/07 15:15:07 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_up(t_play *p, char **map)
{
	double		step_size;
	double		step;

	step = 0;
	step_size = 0.1;
	while (step < p->move_speed)
	{
		if (map[(int)(p->pos.y + p->dir.y * step_size)][(int)p->pos.x] != '1')
			p->pos.y += p->dir.y * step_size;
		if (map[(int)p->pos.y][(int)(p->pos.x + p->dir.x * step_size)] != '1')
			p->pos.x += p->dir.x * step_size;
		step += step_size;
	}
}

void	ft_move_down(t_play *p, char **map)
{
	double		step_size;
	double		step;

	step = 0;
	step_size = 0.1;
	while (step < p->move_speed)
	{
		if (map[(int)(p->pos.y - p->dir.y * step_size)][(int)p->pos.x] != '1')
			p->pos.y -= p->dir.y * step_size;
		if (map[(int)p->pos.y][(int)(p->pos.x - p->dir.x * step_size)] != '1')
			p->pos.x -= p->dir.x * step_size;
		step += step_size;
	}
}

void	ft_move_left(t_play *p, char **map)
{
	double		step_size;
	double		step;

	step = 0;
	step_size = 0.1;
	while (step < p->move_speed)
	{
		if (map[(int)p->pos.y][(int)(p->pos.x - p->dir.y * step_size)] != '1')
			p->pos.x -= p->dir.y * step_size;
		if (map[(int)(p->pos.y + p->dir.x * step_size)][(int)p->pos.x] != '1')
			p->pos.y += p->dir.x * step_size;
		step += step_size;
	}
}

void	ft_move_right(t_play *p, char **map)
{
	double		step_size;
	double		step;

	step = 0;
	step_size = 0.1;
	while (step < p->move_speed)
	{
		if (map[(int)p->pos.y][(int)(p->pos.x + p->dir.y * step_size)] != '1')
			p->pos.x += p->dir.y * step_size;
		if (map[(int)(p->pos.y - p->dir.x * step_size)][(int)p->pos.x] != '1')
			p->pos.y -= p->dir.x * step_size; 
		step += step_size;
	}
}
