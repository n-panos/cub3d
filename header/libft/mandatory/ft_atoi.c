/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:17:01 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/07 11:37:28 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// convertir a int un numero pasado en string

int	ft_atoi(const char *str)
{
	unsigned long long int	suma;
	int						signo;

	suma = 0;
	signo = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		signo = 1;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9' && *str != '\0')
	{
		if (suma < 9223372036854775807)
		{
			suma = suma * 10 + (*str - '0');
			str++;
		}
		else
			return (signo - 1);
	}
	if (signo == 1)
		return (-suma);
	return (suma);
}
