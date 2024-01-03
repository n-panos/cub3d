/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:04 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/03 11:18:09 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	leaks(void)
{
	system("leaks -q cub3D");
}

int	main(int argc, char **argv)
{
	t_map	*map;

	//atexit(leaks);
	if (argc != 2)
		return (ft_putstr_fd("argc diferente de 2", 2), 0);
	map = ft_init_map();
	ft_parse(map, argv[1]);
	ft_game(map);
	ft_free_map(map);
	return (0);
}

void	ft_exit_err(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_free_map(t_map *map)
{
	if (map->map)
		ft_mtx_free(map->map);
	map->map = NULL;
	free(map->north_path);
	map->north_path = NULL;
	free(map->south_path);
	map->south_path = NULL;
	free(map->west_path);
	map->west_path = NULL;
	free(map->east_path);
	map->east_path = NULL;
	if (map->spawn)
		free(map->spawn);
	map->spawn_orient = '0';
	free(map);
}

void	ft_mtx_print(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		printf("%s\n", mtx[i]);
		++i;
	}
}
