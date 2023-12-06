/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:01:04 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/06 11:47:59 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

//busca en la cadena de memoria si existe el caracter c con un 
//tamaño limite (ojo con bus error)

void	*ft_memchr(const void *str, int c, size_t len)
{
	char	*s;

	s = (char *)str;
	while (len--)
	{
		if (*s == c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
