/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:28:30 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/09 10:32:11 by ipanos-o         ###   ########.fr       */
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
}			t_game;

int		ft_game(t_map *map);
int		ft_keys(int key_code, t_game *cubd);

//		INIT - FREE

t_game	*ft_init_game(t_map *map);
int		ft_end_game(t_game *game);

//		IMAGE - DRAWING

void	ft_draw_map(t_game *cubd);
void	ft_minimap(t_game *cubd);
void	ft_cuadriculas(t_game *cubd, int x_init, int y_init);

#endif