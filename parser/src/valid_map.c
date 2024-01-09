/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:29:37 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/09 13:10:50 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_valid_texture(t_map *map)
{
	if (map->north_path == NULL)
		ft_map_error(map, "Map error, north path not set");
	if (map->south_path == NULL)
		ft_map_error(map, "Map error, south path not set");
	if (map->east_path == NULL)
		ft_map_error(map, "Map error, east path not set");
	if (map->west_path == NULL)
		ft_map_error(map, "Map error, west path not set");
	if (map->ceiling->r == -1 || map->ceiling->g == -1 || map->ceiling->b == -1)
		ft_map_error(map, "Map error, ceiling rgb not set");
	if (map->floor->r == -1 || map->floor->g == -1 || map->floor->b == -1)
		ft_map_error(map, "Map error, floor rgb not set");
}

void	ft_valid_chars(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			c = map->map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (map->spawn_orient != '0')
					ft_map_error(map, "Map error, spawn duplicated");
				map->spawn_orient = c;
				map->map[i][j] = 'p';
				map->spawn = ft_pos_init(j, i);
			}
			else if (c != '0' && c != '1' && c != ' ')
				ft_map_error(map, "Map error, invalid character");
			++j;
		}
		++i;
	}
}

int	ft_valid_map(t_map *map)
{
	int		ret;
	int		i;
	char	**mtx;

	i = 0;
	while (map->map[i] && map->map[i + 1])
		++i;
	if (i < 2)
		ft_map_error(map, "Map error, map too narrow");
	mtx = ft_mtx_cpy(map->map);
	ret = ft_paint_map(mtx);
	if (ret == 0)
		ret = ft_only_ones(mtx[0]);
	if (ret == 0)
		ret = ft_only_ones(mtx[i]);
	ft_mtx_free(mtx);
	if (ret == 1)
		ft_map_error(map, "Map error, map not closed");
	return (0);
}
