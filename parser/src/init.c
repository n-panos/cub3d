/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:20:27 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/11 11:26:38 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*ft_init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map *));
	map->map = NULL;
	map->north_path = NULL;
	map->south_path = NULL;
	map->west_path = NULL;
	map->east_path = NULL;
	map->floor_rgb[0] = -1;
	map->floor_rgb[1] = -1;
	map->floor_rgb[2] = -1;
	map->ceiling_rgb[] = -1;
	map->spawn_orient = '0';
}

t_pos	*ft_pos_init(int x, int y)
{
	t_pos	*new_pos;

	new_pos = malloc(sizeof(t_pos));
	ft_give_coords(new_pos, x, y);
	return (new_pos);
}

int	ft_give_coords(t_pos *vector, int x, int y)
{
	if (!vector || x < 0 || y < 0)
		return (1);
	vector->x = x;
	vector->y = y;
	return (0);
}

int	*ft_rgb(char *r, char *g, char *b)
{
	int	ret[3];

	
}
