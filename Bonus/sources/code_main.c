/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:02:49 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/06 17:02:51 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

/*
** get proper size
*/

static size_t		get_size(t_statement *statement, unsigned y)
{
	if (statement->args_types[y] == T_REG)
		return (1);
	else if (statement->args_types[y] == T_IND)
		return (IND_SIZE);
	else
		return (statement->op->t_dir_size);
}

/*
** recode
*/

static void			process_arg(t_parser *parser,
									t_statement *statement,
									unsigned y)
{
	size_t size;

	size = get_size(statement, y);
	if (parser->code_size - parser->pos >= (int32_t)size)
	{
		statement->args[y] = bytecode_to_int32(&parser->code[parser->pos],
													size);
		parser->pos += size;
		if (statement->args_types[y] == T_REG && statement->args[y] <= 0)
			register_error(parser);
	}
	else
		length_error(parser);
}

/*
** send to recode one by one
*/

static void			process_args(t_parser *parser, t_statement *statement)
{
	unsigned y;

	y = 0;
	while (y < statement->op->args_num)
	{
		process_arg(parser, statement, y);
		y++;
	}
}

/*
** get and set arg types according to op.h, comparing arg types,
** recode one by one
*/

static t_statement	*process_statement(t_parser *parser)
{
	t_statement	*statement;
	uint8_t		op_code;

	statement = init_statement();
	op_code = parser->code[parser->pos];
	if (op_code >= 0x01 && op_code <= 0x10)
	{
		parser->pos++;
		statement->op = &g_op[INDEX(op_code)];
		if (statement->op->args_types_code && parser->pos >= parser->code_size)
			length_error(parser);
		process_arg_types(parser, statement);
		if (is_arg_types_valid(statement))
		{
			if (statement->op->args_types_code)
				parser->pos++;
			process_args(parser, statement);
		}
		else
			arg_types_code_error(parser);
	}
	else
		op_code_error(parser);
	return (statement);
}

/*
** recode champion's exec code
*/

void				process_exec_code(t_parser *parser)
{
	while (parser->pos < parser->code_size)
		add_stmnt(&(parser->statements), process_statement(parser));
}
