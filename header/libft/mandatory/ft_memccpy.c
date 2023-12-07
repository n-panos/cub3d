/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:21:30 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/07 11:39:48 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copia en destino lo que haya en src hasta un tamaño tope "len" o 
//hasta encontrar el caracter "c" incluido (no cierra string con /0)

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	char	*s;
	char	*d;

	d = (char *)dst;
	s = (char *)src;
	while (len--)
	{
		*d = *s;
		if (*s == (char)c)
		{
			dst++;
			return (dst);
		}
		dst++;
		d++;
		s++;
	}
	return (NULL);
}
