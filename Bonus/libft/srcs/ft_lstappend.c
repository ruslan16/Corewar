/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 23:48:34 by sirvin            #+#    #+#             */
/*   Updated: 2020/11/25 23:48:34 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstappend(t_list **lst, t_list *new)
{
	t_list	*list;

	if (lst && (*lst) != NULL)
	{
		list = *lst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
	else if (lst)
		(*lst) = new;
}
