/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:39:42 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/29 14:09:40 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_give_coords(t_pos *vector, int x, int y)
{
	if (!vector)
		return (1);
	vector->x = x;
	vector->y = y;
	return (0);
}

int	ft_aredigit_atoi(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (ft_atoi(str));
}

char	*ft_space(char *str)
{
	char	*aux;
	char	*conc;

	if (!str)
		return (str);
	aux = str;
	while (*aux)
	{
		if (*aux == '\t')
		{
			conc = aux + 1;
			*aux = '\0';
			str = ft_strfjoin(str, "    ");
			str = ft_strfjoin(str, conc);
		}
		++aux;
	}
	while (*str == ' ')
		str++;
	return (str);
}
