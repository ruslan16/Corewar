/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 22:52:12 by admin             #+#    #+#             */
/*   Updated: 2021/01/08 22:53:11 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*elem;

	if (alst != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			elem = *alst;
			while (elem->next != NULL)
				elem = elem->next;
			elem->next = new;
		}
	}
}
