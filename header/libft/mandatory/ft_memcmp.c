/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:18:30 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/07 11:39:48 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//comprueba si dos cadenas son iguales con tamaño limite

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = str1;
	s2 = str2;
	while (len--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
