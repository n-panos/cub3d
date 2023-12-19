#include "cub3d.h"

void    ft_valid_texture(t_map *map)
{
    if (map->north_path == NULL)
		ft_map_error(map, "Map error, north path not set");
    if (map->south_path == NULL)
        ft_map_error(map, "Map error, south path not set");
    if (map->east_path == NULL)
        ft_map_error(map, "Map error, east path not set");
    if (map->west_path == NULL)
        ft_map_error(map, "Map error, west path not set");
    if (map->ceiling.r == -1 || map->ceiling.g == -1 || map->ceiling.b == -1)
		ft_map_error(map, "Map error, ceiling rgb not set");
	if (map->floor.r == -1 || map->floor.g == -1 || map->floor.b == -1)
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
			}
			else if (c != '0' && c != '1')
				ft_map_error(map, "Map error, invalid character");
			++j;
		}
		++i;
	}
}

int    ft_valid_map(char **map)
{
	int	i;
	int	j;

	if (ft_only_ones(map[0]) == 1)
		return (1);
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_search_c
			++j;
		}
		++i;
	}
	if (ft_only_ones(map[i]) == 1)
		return (1);
	return (0);
}

int	ft_only_ones(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (1);
		++i;
	}
	return (0);
}

int	ft_search_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_paint_map(t_map *map)
{
	char	**aux_map;
	int		flag;
	int		i;
	int		j;

	aux_map = ft_mtx_cpy(map->map);
	flag = 1;
	while (flag == 1)
		flag = ft_search_mtx(aux_map);
	i = 1;
	while (aux_map[i])
	{
		j = 1;
		while (aux_map[i][j])
		{
			if (aux_map[i][j] == 'c' || aux_map[i][j] == 'e')
				flag = 4;
			j++;
		}
		i++;
	}
	ft_free_mtx(aux_map);
	return (flag);
}

int	ft_search_mtx(char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 1;
	ret = 0;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'p')
				ret = ft_change_ps(map, i, j, ret);
			j++;
		}
		i++;
	}
	return (ret);
}

int	ft_change_ps(char **map, int i, int j, int ret)
{
	if (map[i + 1][j] == '0')
	{
		map[i + 1][j] = 'p';
		ret = 1;
	}
	if (map[i - 1][j] == '0')
	{
		map[i - 1][j] = 'p';
		ret = 1;
	}
	if (map[i][j + 1] == '0')
	{
		map[i][j + 1] = 'p';
		ret = 1;
	}
	if (map[i][j - 1] == '0')
	{
		map[i][j - 1] = 'p';
		ret = 1;
	}
	return (ret);
}
