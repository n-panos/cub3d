/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:40:11 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/06 11:47:59 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//escribe en el fd el string "s"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s + i != NULL && s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
