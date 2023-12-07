/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:20:02 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/07 11:39:48 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// llenar de 0s un string de longitud conocida

void	ft_bzero(void *str, size_t n)
{
	char	*ptr;

	ptr = (char *)str;
	while (n)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}
