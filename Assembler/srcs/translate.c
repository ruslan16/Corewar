/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:05:09 by sirvin            #+#    #+#             */
/*   Updated: 2020/12/11 23:55:53 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

void		write_header(int fd, char *s, int len, int n_val)
{
	char	out;
	int		i;

	i = 0;
	while (i < 4)
	{
		out = (n_val & (0xff << ((8 * (3 - i))))) >> ((8 * (3 - i)));
		ft_putchar_fd(out, fd);
		i++;
	}
	while (len >= 0)
	{
		ft_putchar_fd(*s++, fd);
		len--;
	}
}

void		translate_line(int fd, t_champion *champ, t_op *op)
{
	t_line	*line;
	t_list	*tmp;
	int		i;

	line = champ->lines;
	write_header(fd, champ->header->prog_name, PROG_NAME_LENGTH + 3,
					champ->header->magic);
	write_header(fd, champ->header->comment,
			COMMENT_LENGTH + 3, champ->bytecount);
	while (line)
	{
		i = 0;
		while (i < line->param_count)
			get_arg_byte(line, i++, op[line->opcode - 1].half_size,
							champ->arg_label);
		tmp = line->bytecode;
		while (tmp)
		{
			ft_putchar_fd(((char*)tmp->content)[0], fd);
			tmp = tmp->next;
		}
		line = line->next;
	}
}

int			translate_opname(t_line *line, t_op op, t_champion *champ)
{
	int		bytecount;
	char	byte;
	int		i;

	bytecount = 0;
	line->bytecode = NULL;
	if (!add_bytecode(&line->bytecode, line->opcode))
		return (0);
	bytecount++;
	if (op.acb)
	{
		byte = get_acb_byte(line);
		if (!add_bytecode(&line->bytecode, byte))
			return (0);
		bytecount++;
	}
	i = 0;
	while (i < line->param_count)
	{
		bytecount += get_count_bytes(line->param_type[i], op.half_size);
		i++;
	}
	champ->bytecount += bytecount;
	return (1);
}
