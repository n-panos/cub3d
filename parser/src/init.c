/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:20:27 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/15 10:06:40 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*ft_init_map(char **parsed)
{
	t_map	*map;
	int		i;
	char	*str;

	map = malloc(sizeof(t_map *));
	i = 0;
	map->map = NULL;
	map->north_path = NULL;
	map->south_path = NULL;
	map->west_path = NULL;
	map->east_path = NULL;
	ft_rgb(&(map->floor), "-1", "-1", "-1");
	ft_rgb(&(map->ceiling), "-1", "-1", "-1");
	while (parsed[i])
	{
		str = ft_parse_line(map, parsed[i]);
		if (str)
		{
			ft_free_map(map);
			ft_exit_err(str);
		}
		++i;
	}
	return (map);
}

char	*ft_parse_line(t_map *map, char *str)
{
	char	*line;
	char	*ret;

	line = str;
	line = ft_space(line);
	ret = NULL;
	if (line[0] == '\0')
		return (ret);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		ret = ft_distribute_line(line, map->north_path);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		ret = ft_distribute_line(line, map->south_path);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		ret = ft_distribute_line(line, map->west_path);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		ret = ft_distribute_line(line, map->east_path);
	else if (line[0] == 'F' && line[1] == ' ')
		ret = ft_distribute_rgb(line, &map->floor);
	return (ret);
}

char	*ft_distribute_rgb(char *line, t_rgb *rgb)
{
	char	**mtx;
	int		i;

	line += 2;
	mtx = ft_split(line, ',');
	i = 0;
	while (mtx[i])
		++i;
	if (i != 3)
		ft_rgb(rgb, "-1", "-1", "-1");
	else
		ft_rgb(rgb, mtx[0], mtx[1], mtx[2]);
	ft_mtx_free(mtx);
}

char	*ft_distribute_line(char *line, char *path)
{
	char	*aux;
	int		i;

	if (path != NULL)
		return ("Invalid map, duplicated path");
	line += 3;
	aux = line;
	i = 0;
	while (aux[i])
	{
		if (aux[i] == ' ')
		{
			++i;
			break ;
		}
		++i;
	}
	aux = ft_space(aux);
	if (aux != '\0')
		return ("Invalid texture path");
	path = ft_strdup(line);
	return (NULL);
}

t_pos	*ft_pos_init(int x, int y)
{
	t_pos	*new_pos;

	new_pos = malloc(sizeof(t_pos));
	ft_give_coords(new_pos, x, y);
	return (new_pos);
}
