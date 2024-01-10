/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:28:30 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/10 12:17:31 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_game
{
	t_map	*map;
	void	*mlx;
	void	*window;
	t_pos	*player;
	t_pos	*ray;
	float	p_angle;
}			t_game;

int		ft_game(t_map *map);
int		ft_keys(int key_code, t_game *cubd);

//		INIT - FREE

t_game	*ft_init_game(t_map *map);
int		ft_end_game(t_game *game);

//		IMAGE - DRAWING

void	ft_minimap(t_game *cubd);
void	ft_draw_map(t_game *cubd);
void	ft_draw_player(t_game *cubd, int color);
void	ft_cuadriculas(t_game *cubd, int x_init, int y_init);

//	UTILS

void	ft_draw_rect(t_game *cubd, t_pos start, t_pos end, int color);
void	ft_draw_dir(t_game *cubd, int color);

//		MOVE

void	ft_move(t_game *cubd, int dir);
void	ft_turn(t_game *cubd, int dir);

#endif