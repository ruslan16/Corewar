/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_parce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:58:14 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/06 16:58:16 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

int32_t			bytecode_to_int32(const uint8_t *byte, size_t size)
{
	int32_t	result;
	t_bool	sign;
	int		i;

	result = 0;
	sign = (t_bool)(byte[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((byte[size - 1] ^ 0xFF) << (i++ * 8));
		else
			result += byte[size - 1] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

/*
** First 4 bytes must be COREWAR_EXEC_MAGIC
** parse_int32 reads it and converts with bytecode_to_int32
*/

static int32_t	parse_int32(int fd)
{
	ssize_t	size;
	uint8_t	buff[4];

	size = read(fd, &buff, 4);
	if (size == -1)
		terminate(ERR_READ_FILE);
	if (size < 4)
		terminate(ERR_INVALID_FILE);
	return (bytecode_to_int32(buff, 4));
}

/*
** gets string
*/

static char		*parse_str(int fd, size_t length)
{
	ssize_t	size;
	char	*buff;

	if (!(buff = ft_strnew(length)))
		terminate(ERR_STR_INIT);
	size = read(fd, buff, length);
	if (size == -1)
		terminate(ERR_READ_FILE);
	if (size < (ssize_t)length)
		terminate(ERR_INVALID_FILE);
	return (buff);
}

/*
** gets code
*/

static uint8_t	*parse_code(int fd, size_t length)
{
	ssize_t	size;
	uint8_t	*buff;
	uint8_t	byte;

	if (!(buff = ft_memalloc(length)))
		terminate(ERR_CODE_INIT);
	size = read(fd, buff, length);
	if (size == -1)
		terminate(ERR_READ_FILE);
	if (size < (ssize_t)length || read(fd, &byte, 1) != 0)
		terminate(ERR_INVALID_FILE);
	return (buff);
}

/*
** Check Magic header, Get Champion's name, Check for NULL presence,
** Check Champion exec code size, read comment, get champ code
*/

void			parse_bytecode(t_parser *parser)
{
	if (parse_int32(parser->fd) != COREWAR_EXEC_MAGIC)
		terminate(ERR_INVALID_MAGIC);
	parser->name = parse_str(parser->fd, PROG_NAME_LENGTH);
	if (parse_int32(parser->fd) != 0)
		terminate(ERR_NO_NULL);
	if ((parser->code_size = parse_int32(parser->fd)) < 0)
		terminate(ERR_INVALID_CODE_SIZE);
	parser->comment = parse_str(parser->fd, COMMENT_LENGTH);
	if (parse_int32(parser->fd) != 0)
		terminate(ERR_NO_NULL);
	parser->code = parse_code(parser->fd, (size_t)parser->code_size);
}
