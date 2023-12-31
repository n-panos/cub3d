/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:28:20 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/09 13:12:03 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>

//	open close etc
# include <fcntl.h>

//	perror && printf
# include <stdio.h>

//	strerror(errno)
# include <errno.h>

//	exit
# include <stdlib.h>

# include "../parser/header/parser.h"
# include "../game/header/game.h"
# include "libft/includes/libft.h"
# include "mlx/mlx.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

# define WIDTH 1920
# define HEIGHT 1080
# define MAP_W 1360
# define MAP_H 780

# define DIST 20
# define SPEED 1

void	ft_exit_err(char *str);
void	ft_free_map(t_map *map);

//	testing fts

void	ft_mtx_print(char **mtx);

#endif