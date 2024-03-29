/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:04 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/02/01 09:44:04 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	ft_mtx_print(char **mtx);

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
	ft_mtx_print(map->map);
	ft_game(map);
	return (0);
}

void	ft_exit_err(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
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
