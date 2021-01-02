/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:25:34 by sirvin            #+#    #+#             */
/*   Updated: 2020/11/24 22:01:39 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

int			get_opcode(char *opname)
{
	int		i;

	i = 0;
	while (i < 16 && ft_strcmp(g_op_tab[i].opname, opname))
		i++;
	if (i < 16)
		return (g_op_tab[i].opcode);
	return (0);
}

char		*get_arguments(char *s, t_line *line)
{
	char	**arg;
	int		len;
	char	*ret;

	ret = NULL;
	if (!(arg = ft_strsplit(s, SEPARATOR_CHAR)))
		return (ft_strdup("Failed to malloc parameters"));
	if ((len = count_arg(arg)) > MAX_ARGS_NUMBER)
		ret = ft_strdup("Too many parameters");
	else
		line->param_count = len;
	while (len--)
	{
		if (!ret && (line->param_type[len] = get_type_arg(arg[len])))
			line->param[len] = ft_strtrim(arg[len]);
		else if (!ret)
			ret = ft_strdup("Invalid parameter formatting");
		ft_strdel(&arg[len]);
	}
	free(arg);
	return (ret);
}

char		*get_opname(char **s, char **opname)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[0][i] && ft_strchr(LABEL_CHARS, s[0][i]))
		i++;
	if (s[0][i] == DIRECT_CHAR || ft_isspace(s[0][i]))
	{
		len = ft_strlen(*s) - ft_strlen(*s + i);
		if (!(*opname = ft_strsub(*s, 0, len)))
			return (ft_strdup("Failed to malloc operation name"));
		i++;
		while (ft_isspace(s[0][i]))
			i++;
		*s += i;
		if (**s != SEPARATOR_CHAR)
			return (NULL);
	}
	return (ft_strdup("Invalid character after operation name"));
}

char		*get_label(char **s, char **label)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[0][i] && ft_strchr(LABEL_CHARS, s[0][i]))
		i++;
	if (s[0][i] == LABEL_CHAR && i)
	{
		len = ft_strlen(*s) - ft_strlen(*s + i++);
		if (!(*label = ft_strsub(*s, 0, len)))
			return (ft_strdup("Failed to malloc label"));
		i++;
		while (ft_isspace(s[0][i]))
			i++;
		*s += i;
	}
	if (!i)
		return (ft_strdup("Label starts with a char not in LABEL_CHARS"));
	return (NULL);
}
