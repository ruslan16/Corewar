/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:52:15 by sirvin            #+#    #+#             */
/*   Updated: 2020/11/23 21:57:49 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

int			fill_label(t_label *arg_lab, t_label *lab, t_error **error)
{
	t_label	*label;
	int		ret;

	ret = 0;
	while (arg_lab)
	{
		label = lab;
		while (label)
		{
			if (!ft_strcmp(arg_lab->name, label->name))
			{
				arg_lab->dist = label->dist - arg_lab->dist;
				break ;
			}
			label = label->next;
		}
		if (!label)
			ret += add_error(ft_strdup(arg_lab->line),
							ft_strdup("Label requested not declared"),
							arg_lab->line_nb, error);
		if (ret > 19)
			return (ret);
		arg_lab = arg_lab->next;
	}
	return (ret);
}

int			check_is_empty(char *str)
{
	char	*tmp;
	char	*tmp2;
	char	*label;
	char	*ret;

	if (!str)
		return (1);
	tmp = ft_strtrim(str);
	tmp2 = tmp;
	label = NULL;
	ret = get_label(&tmp, &label);
	if (label)
		ft_strdel(&label);
	if (ret)
		ft_strdel(&ret);
	if (!tmp || !*tmp || *tmp == COMMENT_CHAR || *tmp == ALT_COMMENT)
	{
		ft_strdel(&tmp2);
		return (1);
	}
	ft_strdel(&tmp2);
	return (0);
}

int			count_arg(char **arg)
{
	int		i;

	i = 0;
	while (arg && arg[i])
		i++;
	return (i);
}
