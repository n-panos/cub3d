/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:05:26 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/06 11:47:59 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//funcion de revision de listas, añade un elemento mas al final de la lista

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	end = *lst;
	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			end = ft_lstlast(*lst);
			end->next = new;
		}
	}
}
