/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:28:25 by ipanos-o          #+#    #+#             */
/*   Updated: 2020/12/23 14:13:54 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//escribe en fd el caracter c

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
