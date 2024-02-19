/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:20:27 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/02/07 16:32:33 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*ft_init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_exit_err("Error allocating map");
	map->map = NULL;
	map->spawn = ft_posint_init(0, 0);
	map->spawn_orient = '0';
	map->error_ret = NULL;
	map->north_path = NULL;
	map->south_path = NULL;
	map->west_path = NULL;
	map->east_path = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
	return (map);
}

t_pos_int	*ft_posint_init(int x, int y)
{
	t_pos_int	*new_pos;

	new_pos = malloc(sizeof(t_pos_int *));
	if (ft_give_coords(new_pos, x, y) == 1)
		return (NULL);
	return (new_pos);
}

t_rgb	*ft_rgb(char *r, char *g, char *b)
{
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	rgb->r = ft_aredigit_atoi(r);
	rgb->g = ft_aredigit_atoi(g);
	rgb->b = ft_aredigit_atoi(b);
	return (rgb);
}

void	ft_map_error(t_map *map, char *str)
{
	ft_free_map(map);
	ft_exit_err(str);
}
