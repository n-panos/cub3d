/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:06:57 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/02 10:32:38 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_file(char *argv)
{
	char	*aux;
	char	*map;
	int		fd;
	char	**ret;

	fd = ft_open_file(argv);
	map = ft_strdup("");
	while (1)
	{
		aux = get_next_line(fd);
		if (aux == NULL)
			break ;
		if (ft_strncmp(aux, "\n", 1) == 0 && ft_strlen(aux) == 1)
			map = ft_strfjoin(map, " \n");
		else
			map = ft_strfjoin(map, aux);
		free(aux);
	}
	close(fd);
	ret = ft_split(map, '\n');
	free(map);
	return (ret);
}

int	ft_open_file(char *argv)
{
	char	*aux;
	int		fd;

	aux = ft_strnstr(argv, ".cub", ft_strlen(argv));
	if (aux == NULL || ft_strlen(aux) != 4)
		ft_exit_err("Error\nNombre de mapa incorrecto");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit_err("Error\nEl mapa no existe o no hay permisos para abrirlo");
	return (fd);
}
