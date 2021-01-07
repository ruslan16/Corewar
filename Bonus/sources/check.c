/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:59:55 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/06 16:59:57 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

/*
** check name length
*/

void	check_name(t_parser *parser)
{
	size_t y;

	y = ft_strlen(parser->name);
	while (y < PROG_NAME_LENGTH)
	{
		if (parser->name[y])
		{
			name_warning(y);
			return ;
		}
		y++;
	}
}

/*
** check comment length
*/

void	check_comment(t_parser *parser)
{
	size_t y;

	y = ft_strlen(parser->comment);
	while (y < COMMENT_LENGTH)
	{
		if (parser->comment[y])
		{
			comment_warning(y);
			return ;
		}
		y++;
	}
}

/*
** check if set correctly
*/

void	check_types_code(t_parser *parser,
							int8_t args_types_code,
							int all_args)
{
	int		arg_num;
	int8_t	type;

	arg_num = 4;
	while (arg_num > all_args)
	{
		type = (int8_t)((args_types_code >> (2 * (4 - arg_num))) & 0x3);
		if (type != 0)
		{
			types_code_warning((size_t)parser->pos);
			return ;
		}
		arg_num--;
	}
}

/*
** comparing arg types
*/

t_bool	is_arg_types_valid(t_statement *statement)
{
	int32_t y;

	y = 0;
	while (y < statement->op->args_num)
	{
		if (!(statement->args_types[y] & statement->op->args_types[y]))
			return (false);
		y++;
	}
	return (true);
}
