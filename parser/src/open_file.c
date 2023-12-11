/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:06:57 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/11 11:06:58 by ipanos-o         ###   ########.fr       */
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
		map = ft_strfjoin(map, aux);
		free(aux);
	}
	close(fd);
	ret = ft_split(map, '\n');
	free(map);
	return (ret);
}

char	*ft_space(char *str)
{
	char	*aux;

	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
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
