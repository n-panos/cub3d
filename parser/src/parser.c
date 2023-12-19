/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:06:49 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/19 11:17:08 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*ft_parse(char *argv)
{
	char	**mtx;
	t_map	*map;

	mtx = ft_file(argv);
	map = ft_init_map();
	ft_solve_map(map, mtx);
	//ft_check_valid_texture(map);
	//ft_check_valid_map(map->map);
	ft_mtx_print(mtx);
	free(mtx);
}

int	ft_solve_map(t_map *map, char **mtx)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while (mtx[i] && map->map_len == 0)
	{
		str = ft_parse_line(map, mtx[i]);
		if (ft_strncmp(str, "exit", 4))
			break ;
		if (str)
		{
			ft_free_map(map);
			ft_exit_err(str);
		}
		++i;
	}
	ft_distribute_map(map, mtx, i);
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
	ret = ft_parse_textures(map, line);
	return (ret);
}

char	*ft_parse_textures(t_map *map, char *line)
{
	char	*ret;

	ret = NULL;
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
	else if (line[0] == 'C' && line[1] == ' ')
		ret = ft_distribute_rgb(line, &map->ceiling);
	else
		return ("exit");
	return (ret);
}
