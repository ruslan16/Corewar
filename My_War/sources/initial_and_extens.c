/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_and_extens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:25:48 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/06 17:25:51 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

/*
** Here we initialize structures parser and statement; if fail - terminate
*/

t_parser	*init_bytecode_parser(int fd)
{
	t_parser *parser;

	if (!(parser = (t_parser *)ft_memalloc(sizeof(t_parser))))
		terminate(ERR_PARSER_INIT);
	parser->fd = fd;
	parser->name = NULL;
	parser->comment = NULL;
	parser->code_size = 0;
	parser->code = NULL;
	parser->pos = 0;
	parser->statements = NULL;
	return (parser);
}

t_statement	*init_statement(void)
{
	t_statement *statement;

	if (!(statement = (t_statement *)ft_memalloc(sizeof(t_statement))))
		terminate(ERR_STATEMENT_INIT);
	statement->op = NULL;
	statement->next = NULL;
	return (statement);
}

/*
** change file extension
*/

char		*replace_extension(char *file, char *old, char *new)
{
	char	*basename;

	basename = ft_strsub(file, 0, ft_strlen(file) - ft_strlen(old));
	if (!basename)
		terminate(ERR_STR_INIT);
	if (!(file = ft_strjoin(basename, new)))
		terminate(ERR_STR_INIT);
	ft_strdel(&basename);
	return (file);
}
