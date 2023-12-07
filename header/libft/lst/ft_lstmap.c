/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:45:21 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/07 11:39:48 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newrdo;
	t_list	*temp;
	t_list	*begin;

	if (lst)
	{
		temp = lst;
		begin = ft_lstnew(f(temp->content));
		if (!begin)
			return (NULL);
		temp = temp->next;
		while (temp)
		{
			newrdo = ft_lstnew(f(temp->content));
			if (!newrdo)
			{
				ft_lstclear(&begin, del);
				return (NULL);
			}
			ft_lstadd_back(&begin, newrdo);
			temp = temp->next;
		}
		return (begin);
	}
	return (NULL);
}
