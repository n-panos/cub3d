/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:29:45 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/07 11:39:48 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_mtx_cpy(char **mtx)
{
	char	**ret_mtx;
	int		i;
	int		mtx_height;

	mtx_height = ft_mtx_line_cnt(mtx);
	ret_mtx = (char **)malloc(sizeof(char *) * (mtx_height + 1));
	i = 0;
	while (mtx[i])
	{
		ret_mtx[i] = ft_strdup(mtx[i]);
		++i;
	}
	ret_mtx[i] = NULL;
	return (ret_mtx);
}

int	ft_mtx_line_cnt(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		i++;
	}
	return (i);
}
