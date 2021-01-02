/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 23:50:01 by sirvin            #+#    #+#             */
/*   Updated: 2020/11/25 23:50:01 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstcpy(void *content, size_t content_size)
{
	t_list	*res;

	if (!(res = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	res->content = content;
	res->content_size = content_size;
	res->next = NULL;
	return (res);
}
