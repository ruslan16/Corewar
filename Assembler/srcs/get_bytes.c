/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:41:46 by sirvin            #+#    #+#             */
/*   Updated: 2020/11/24 22:41:05 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

static int			get_arg_val(char *param, int param_type, t_label *lab)
{
	char			*label;

	if ((label = ft_strchr(param, LABEL_CHAR)))
	{
		++label;
		while (lab)
		{
			if (!ft_strcmp(lab->name, label) && !lab->used)
			{
				lab->used = 1;
				return (lab->dist);
			}
			lab = lab->next;
		}
	}
	if (param_type == T_IND)
		return (ft_atoi(param));
	else
		return (ft_atoi(param + 1));
}

void				get_arg_byte(t_line *line, int nb, int half, t_label *lab)
{
	unsigned int	val;
	unsigned int	mask;
	int				i;
	char			out;
	int				max;

	val = (unsigned int)get_arg_val(line->param[nb], line->param_type[nb],
									lab);
	mask = 0xff;
	i = 0;
	max = get_count_bytes(line->param_type[nb], half);
	while (i < max && i < 4)
	{
		out = (val & (mask << ((8 * (max - 1 - i))))) >> ((8 * (max - 1 - i)));
		ft_lstappend(&line->bytecode, ft_lstcpy(ft_strdup(&out), 1));
		i++;
	}
}

int					get_count_bytes(int param_type, int half)
{
	if (param_type == T_DIR)
		return (half ? IND_SIZE : DIR_SIZE);
	else if (param_type == T_REG)
		return (1);
	else if (param_type == T_IND)
		return (IND_SIZE);
	return (0);
}

char				get_acb_byte(t_line *line)
{
	char			byte;
	int				i;
	int				value;

	i = 0;
	byte = 0;
	while (i < 3 && line->param_type[i])
	{
		value = (line->param_type[i] == T_REG) ? REG_CODE : value;
		value = (line->param_type[i] == T_IND) ? IND_CODE : value;
		value = (line->param_type[i] == T_DIR) ? DIR_CODE : value;
		byte = byte | (value << (6 - i * 2));
		i++;
	}
	return (byte);
}
