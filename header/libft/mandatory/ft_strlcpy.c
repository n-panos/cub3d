/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:31:05 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/07 11:39:48 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	c;

	if ((dst || src) == '\0')
		return (0);
	c = 0;
	while (src[c] != '\0')
		c++;
	if (dstsize == 0)
		return (c);
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (c);
}
