#include "cub3d.h"

char	*ft_distribute_rgb(char *line, t_rgb *rgb)
{
	char	**mtx;
	int		i;

	line += 1;
	line = ft_space(line);
	mtx = ft_split(line, ',');
	i = 0;
	while (mtx[i])
		++i;
	if (i != 3)
	{
		ft_rgb(rgb, "-1", "-1", "-1");
		ft_mtx_free(mtx);
		return ("Invalid RGB, wrong data");
	}
	ft_rgb(rgb, mtx[0], mtx[1], mtx[2]);
	ft_mtx_free(mtx);
	if (rgb->r == -1 || rgb->g == -1 || rgb->b == -1)
		return ("Invalid RGB, numbers not valid");
	return (NULL);
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
		return ("No texture path");
	path = ft_strdup(line);
	return (NULL);
}

char	*ft_distribute_map(t_map *map, char **mtx, int i)
{
	int		aux;
	char	*str;

	aux = ft_empty_lines(mtx, i);
	map->map = malloc(sizeof(char *) *(ft_mtx_line_cnt(mtx) - i - aux + 1));
	aux = 0;
	while (mtx[i])
	{
		if (mtx[i][0] != '\0')
		{
			map->map[aux] = ft_strdup(mtx[i]);
			++aux;
		}
		++i;
	}
	map->map[aux] = NULL;
	str = mtx[i];
	str = ft_space(str);
	if (str[0] == '\0')
		return (NULL);
	return ("Mapa invalido, linea vacia en medio del mapa");
}

int	ft_empty_lines(char **mtx, int i)
{
	int		j;
	char	*str;

	j = 0;
	while (mtx[i])
	{
		str = mtx[i];
		str = ft_space(str);
		if (str[0] == '\0')
			++j;
		++i;
	}
	return (j);
}
