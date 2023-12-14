/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:06:49 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/14 12:35:32 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*ft_parse(char *argv)
{
	char	**mtx;
	t_map	*map;

	mtx = ft_file(argv);
	map = ft_init_map(mtx);
	ft_mtx_print(mtx);
	free(mtx);
}
