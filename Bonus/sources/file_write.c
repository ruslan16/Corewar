/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:22:26 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/08 12:35:24 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

/*
** Writing all info to file
*/

void	do_write(t_statement *curr, unsigned y, int fd)
{
	if (curr->args_types[y] == T_DIR)
	{
		ft_putstr_fd(" %", fd);
		ft_putnbr_fd((long)curr->args[y], fd);
	}
	else if (curr->args_types[y] == T_IND)
	{
		ft_putstr_fd(" ", fd);
		ft_putnbr_fd((long)curr->args[y], fd);
	}
	else if (curr->args_types[y] == T_REG)
	{
		ft_putstr_fd(" r", fd);
		ft_putnbr_fd((long)curr->args[y], fd);
	}
	if (y < curr->op->args_num - 1)
		ft_putstr_fd(",", fd);
}

void	write_name_comment(int fd, t_parser *parser)
{
	ft_putstr_fd(".name ", fd);
	write(fd, "\"", 1);
	ft_putstr_fd(parser->name, fd);
	write(fd, "\"", 1);
	ft_putstr_fd("\n", fd);
	ft_putstr_fd(".comment ", fd);
	write(fd, "\"", 1);
	ft_putstr_fd(parser->comment, fd);
	write(fd, "\"", 1);
	ft_putstr_fd("\n\n", fd);
}

void	write_dsm_file(int fd, t_parser *parser)
{
	t_statement	*curr;
	unsigned	y;

	write_name_comment(fd, parser);
	curr = parser->statements;
	while (curr)
	{
		ft_putstr_fd(curr->op->name, fd);
		y = 0;
		while (y < curr->op->args_num)
		{
			do_write(curr, y, fd);
			y++;
		}
		ft_putstr_fd("\n", fd);
		curr = curr->next;
	}
}
