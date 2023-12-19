/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:20:27 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/19 19:51:29 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*ft_init_map(void)
{
	t_map	*map;
	char	*str;

	map = malloc(sizeof(t_map *));
	map->spawn = ft_pos_init(0, 0);
	map->spawn_orient = '0';
	map->map = NULL;
	map->north_path = NULL;
	map->south_path = NULL;
	map->west_path = NULL;
	map->east_path = NULL;
	ft_rgb(&(map->floor), "-1", "-1", "-1");
	ft_rgb(&(map->ceiling), "-1", "-1", "-1");
	return (map);
}

t_pos	*ft_pos_init(int x, int y)
{
	t_pos	*new_pos;

	new_pos = malloc(sizeof(t_pos));
	ft_give_coords(new_pos, x, y);
	return (new_pos);
}

void	ft_map_error(t_map *map, char *str)
{
	ft_free_map(map);
	ft_exit_err(str);
}
