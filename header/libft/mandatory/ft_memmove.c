/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:46:37 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/06 11:56:33 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//mueve la cadena a otra parte de la memoria

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	const char	*sfinal;
	char		*dfinal;

	d = dst;
	s = src;
	if (src == NULL && dst == NULL)
		return (NULL);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
		return (dst);
	}
	sfinal = s + len - 1;
	dfinal = d + len - 1;
	while (len--)
	{
		*dfinal = *sfinal;
		dfinal--;
		sfinal--;
	}
	return (dst);
}
