/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:48:57 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/06 16:49:00 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

static uint8_t	get_arg_typ(int8_t arg)
{
	if (arg == DIR_CODE)
		return (T_DIR);
	else if (arg == REG_CODE)
		return (T_REG);
	else if (arg == IND_CODE)
		return (T_IND);
	else
		return (0);
}

static void		set_arg_type(int8_t arg_code,
								int8_t index,
								t_statement *statement)
{
	statement->args_types[INDEX(index)] = get_arg_typ(arg_code);
}

/*
** get and set arg types according to op.h
*/

void			process_arg_types(t_parser *parser, t_statement *statement)
{
	int8_t args_types_code;

	if (statement->op->args_types_code)
	{
		args_types_code = parser->code[parser->pos];
		if (statement->op->args_num >= 1)
			set_arg_type((int8_t)((args_types_code & 0xC0) >> 6), 1, statement);
		if (statement->op->args_num >= 2)
			set_arg_type((int8_t)((args_types_code & 0x30) >> 4), 2, statement);
		if (statement->op->args_num >= 3)
			set_arg_type((int8_t)((args_types_code & 0xC) >> 2), 3, statement);
		check_types_code(parser, args_types_code, statement->op->args_num);
	}
	else
		statement->args_types[0] = statement->op->args_types[0];
}
