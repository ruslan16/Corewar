/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:08:49 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/06 17:08:51 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

void	op_code_error(t_parser *parser)
{
	int32_t	pref;

	pref = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_putstr_fd("Incorrect operator code at ", 2);
	ft_putnbr_fd(pref + parser->pos, 2);
	ft_putstr_fd(" byte\n", 2);
	exit(0);
}

void	arg_types_code_error(t_parser *parser)
{
	int32_t	pref;

	pref = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_putstr_fd("Incorrect code of arguments types at ", 2);
	ft_putnbr_fd(pref + parser->pos, 2);
	ft_putstr_fd(" byte\n", 2);
	exit(0);
}

void	length_error(t_parser *parser)
{
	int32_t	pref;

	pref = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_putstr_fd("There is not enough bytes at ", 2);
	ft_putnbr_fd(pref + parser->pos, 2);
	ft_putstr_fd(" byte\n", 2);
	exit(0);
}

void	register_error(t_parser *parser)
{
	int32_t	pref;

	pref = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_putstr_fd("Incorrect register's id at ", 2);
	ft_putnbr_fd(pref + parser->pos, 2);
	ft_putstr_fd(" byte\n", 2);
	exit(0);
}
