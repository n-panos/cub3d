/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:06:49 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/09 10:29:30 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parse(t_map *map, char *argv)
{
	char	**mtx;

	mtx = ft_file(argv);
	ft_solve_map(map, mtx);
	free(mtx);
	ft_valid_texture(map);
	ft_valid_chars(map);
	ft_valid_map(map);
	return (0);
}

void	ft_solve_map(t_map *map, char **mtx)
{
	int		i;
	char	*str;

	i = 0;
	while (mtx[i])
	{
		ft_parse_line(map, mtx[i]);
		if (map->error_ret && ft_strncmp(map->error_ret, "exit", 4) == 0)
			break ;
		if (map->error_ret)
			ft_map_error(map, map->error_ret);
		++i;
	}
	while (mtx[i])
	{
		str = mtx[i];
		str = ft_space(str);
		if (str[0] != '\0')
			break ;
		++i;
	}
	ft_distribute_map(map, mtx, i);
	if (map->error_ret)
		ft_map_error(map, map->error_ret);
}

void	ft_parse_line(t_map *map, char *str)
{
	char	*line;

	line = str;
	line = ft_space(line);
	if (line[0] != '\0' && line[1] && line[2])
	{
		if (ft_parse_textures(map, line) == 0)
			ft_parse_rgb(map, line);
	}
}

int	ft_parse_textures(t_map *map, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		if (map->north_path)
			map->error_ret = ft_strdup("Invalid parse, duplicated path");
		else
			map->north_path = ft_distribute_line(line, map);
		return (1);
	}
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	{
		if (map->south_path)
			map->error_ret = ft_strdup("Invalid parse, duplicated path");
		else
			map->south_path = ft_distribute_line(line, map);
		return (1);
	}
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	{
		if (map->west_path)
			map->error_ret = ft_strdup("Invalid parse, duplicated path");
		else
			map->west_path = ft_distribute_line(line, map);
		return (1);
	}
	return (0);
}

int	ft_parse_rgb(t_map *map, char *line)
{
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		if (map->east_path)
			map->error_ret = ft_strdup("Invalid parse, duplicated path");
		else
			map->east_path = ft_distribute_line(line, map);
	}
	else if (line[0] == 'F' && line[1] == ' ')
	{
		if (map->floor)
			map->error_ret = ft_strdup("Invalid RGB, duplicated data");
		else
			map->floor = ft_distribute_rgb(line, map);
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		if (map->ceiling)
			map->error_ret = ft_strdup("Invalid RGB, duplicated data");
		else
			map->ceiling = ft_distribute_rgb(line, map);
	}
	else
		map->error_ret = ft_strdup("exit");
	return (0);
}
