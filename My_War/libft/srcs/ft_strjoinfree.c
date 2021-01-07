/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 23:49:29 by sirvin            #+#    #+#             */
/*   Updated: 2020/11/25 23:49:29 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoinfree(char *ret, char *s1, char *s2)
{
	char *str;

	if (!s1 && !s2)
		return (NULL);
	str = ft_strjoin(s1, s2);
	if (ret)
		free(ret);
	return (str);
}
