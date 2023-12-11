/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:06:49 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/11 11:20:55 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*ft_parse(char *argv)
{
	char	**mtx;
	t_map	*map;

	map = ft_init_map();
	mtx = ft_file(argv);
	ft_mtx_print(mtx);
	free(mtx);
}
