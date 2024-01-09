/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:28:52 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/09 10:28:54 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rgb	*ft_distribute_rgb(char *line, t_map *map)
{
	char	**mtx;
	int		i;
	t_rgb	*rgb;

	line += 1;
	line = ft_space(line);
	mtx = ft_split(line, ',');
	i = 0;
	while (mtx[i])
		++i;
	if (i != 3)
	{
		ft_mtx_free(mtx);
		map->error_ret = ft_strdup("Invalid RGB, wrong data");
		return (NULL);
	}
	rgb = ft_rgb(mtx[0], mtx[1], mtx[2]);
	ft_mtx_free(mtx);
	if (rgb->r == -1 || rgb->g == -1 || rgb->b == -1)
		map->error_ret = ft_strdup("Invalid RGB, numbers not valid");
	return (rgb);
}

char	*ft_distribute_line(char *line, t_map *map)
{
	char	**aux;
	int		i;
	char	*ret;

	aux = ft_split(line, ' ');
	i = ft_mtx_line_cnt(aux);
	ret = NULL;
	if (i == 1)
		map->error_ret = ft_strdup("Invalid parse, no path found");
	else if (i > 2)
		map->error_ret = ft_strdup("Invalid parse, invalid path");
	else
		ret = ft_strdup(aux[1]);
	ft_mtx_free(aux);
	return (ret);
}

void	ft_distribute_map(t_map *map, char **mtx, int i)
{
	int		aux;

	free(map->error_ret);
	map->error_ret = NULL;
	aux = ft_mtx_line_cnt(mtx) - i;
	map->map = malloc(sizeof(char *) * (aux + 1));
	aux = 0;
	while (mtx[i])
	{
		if (!map->error_ret && ft_empty_line(mtx[i]) == 1)
			map->error_ret = ft_strdup("Invalid map, empty line");
		map->map[aux] = ft_strdup(mtx[i]);
		++aux;
		++i;
	}
	map->map[aux] = NULL;
}

int	ft_empty_line(char *line)
{
	char	*empty;

	empty = line;
	empty = ft_space(empty);
	if (empty[0] == '\0')
		return (1);
	return (0);
}
