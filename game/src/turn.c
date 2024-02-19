/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:12:39 by nacho             #+#    #+#             */
/*   Updated: 2024/02/07 15:20:42 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_turn_left(t_game *cubd, double turn_speed)
{
	t_play  *p;
	double	old_dir_x;
	double	old_plane_x;

	p = cubd->player;
	old_dir_x = p->dir.x;
	p->dir.x = p->dir.x * cos(-turn_speed) - p->dir.y * sin(-turn_speed);
	p->dir.y = old_dir_x * sin(-turn_speed) + p->dir.y * cos(-turn_speed);
	old_plane_x = p->plane.x;
	p->plane.x = p->plane.x * cos(-turn_speed) - p->plane.y * sin(-turn_speed);
	p->plane.y = old_plane_x * sin(-turn_speed) + p->plane.y * cos(-turn_speed);
}

void	ft_turn_right(t_game *cubd, double turn_speed)
{
	t_play	*p;
	double	old_dir_x;
	double	old_plane_x;

	p = cubd->player;
	old_dir_x = p->dir.x;
	p->dir.x = p->dir.x * cos(turn_speed) - p->dir.y * sin(turn_speed);
	p->dir.y = old_dir_x * sin(turn_speed) + p->dir.y * cos(turn_speed);
	old_plane_x = p->plane.x;
	p->plane.x = p->plane.x * cos(turn_speed) - p->plane.y * sin(turn_speed);
	p->plane.y = old_plane_x * sin(turn_speed) + p->plane.y * cos(turn_speed);
}
