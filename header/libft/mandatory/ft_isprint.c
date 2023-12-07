/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:16:55 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/07 11:39:48 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// revisa si es un caracter contemplado como imprimible en el codigo ascii

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}
