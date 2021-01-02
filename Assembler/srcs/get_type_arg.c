/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:54:37 by sirvin            #+#    #+#             */
/*   Updated: 2020/12/11 23:38:25 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

int		is_valid_registry(char *s)
{
	int	i;
	int	val;

	i = 0;
	if (s[i] == 'r')
	{
		val = ft_atoi(&s[1]);
		while (ft_isdigit(s[++i]))
			(void)i;
		if (i != 1 && !s[i] && val && val <= REG_NUMBER)
			return (1);
	}
	return (0);
}

int		is_valid_direct(char *s)
{
	int	i;

	i = 0;
	if (s[i] == DIRECT_CHAR)
	{
		s++;
		if (s[i] == LABEL_CHAR)
		{
			s++;
			while (s[i] && ft_strchr(LABEL_CHARS, s[i]))
				i++;
		}
		else if (ft_isdigit(s[i]) || *s++ == '-')
		{
			while (ft_isdigit(s[i]))
				i++;
		}
		if (!s[i] && i)
			return (1);
	}
	return (0);
}

int		is_valid_indirect(char *s)
{
	int	i;

	i = 0;
	if (ft_isdigit(s[i]) || s[i] == LABEL_CHAR || s[i] == '-')
	{
		if (s[i] == LABEL_CHAR)
		{
			i++;
			while (s[i] && ft_strchr(LABEL_CHARS, s[i]))
				i++;
		}
		else if (ft_isdigit(s[i]) || s[i++] == '-')
		{
			while (ft_isdigit(s[i]))
				i++;
		}
		if (!s[i] && i > ((s[1] == LABEL_CHAR || s[1] == '-') ? 1 : 0))
			return (1);
	}
	return (0);
}

int		get_type_arg(char *s)
{
	while (ft_isspace(*s))
		s++;
	if (is_valid_registry(s))
		return (T_REG);
	else if (is_valid_direct(s))
		return (T_DIR);
	else if (is_valid_indirect(s))
		return (T_IND);
	else
		return (0);
}
