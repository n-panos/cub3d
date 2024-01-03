#include "cub3d.h"

int	ft_paint_map(char **map)
{
	int		i;
	int		j;

	i = 1;
	while (i == 1)
		i = ft_search_mtx(map);
	i = 1;
	while (map[i] && map[i + 1])
	{
		if (map[i][0] == 'p')
				return (1);
		j = 1;
		while (map[i][j])
		{
			if (ft_search_sides(map, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_only_ones(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'p')
			return (1);
		++i;
	}
	return (0);
}

int	ft_search_sides(char **map, int i, int j)
{
	int	len;

	if (map[i][j] == 'p')
	{
		len = ft_strlen(map[i - 1]);
		if (len <= j || (map[i - 1][j] != '1' && map[i - 1][j] != 'p'))
			return (1);
		len = ft_strlen(map[i + 1]);
		if (len <= j || (map[i + 1][j] != '1' && map[i + 1][j] != 'p'))
			return (1);
		if (map[i][j - 1] != '1' && map[i][j - 1] != 'p')
			return (1);
		if (map[i][j + 1] != '1' && map[i][j + 1] != 'p')
			return (1);
	}
	return (0);
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
	int	len;

	len = ft_strlen(map[i + 1]);
	if (len >= j && map[i + 1][j] == '0')
	{
		map[i + 1][j] = 'p';
		ret = 1;
	}
	len = ft_strlen(map[i - 1]);
	if (len >= j && map[i - 1][j] == '0')
	{
		map[i - 1][j] = 'p';
		ret = 1;
	}
	if (map[i][j + 1] && map[i][j + 1] == '0')
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
