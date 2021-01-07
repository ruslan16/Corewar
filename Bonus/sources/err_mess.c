/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_mess.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:07:26 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/06 17:07:29 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

void	name_warning(size_t pos)
{
	size_t pref;

	pref = 4;
	ft_putstr_fd("Warning: Name was completed with not null bytes — ", 2);
	ft_putnbr_fd(pref + pos + 1, 2);
	ft_putstr_fd(" \n", 2);
}

void	comment_warning(size_t pos)
{
	size_t pref;

	pref = 4 + PROG_NAME_LENGTH + 4 + 4;
	ft_putstr_fd("Warning: Comment was completed with not null bytes - ", 2);
	ft_putnbr_fd(pref + pos + 1, 2);
	ft_putstr_fd(" \n", 2);
}

void	types_code_warning(size_t pos)
{
	size_t pref;

	pref = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_putstr_fd("Warning: Insignificant bits in code of arguments types ", 2);
	ft_putstr_fd("are not null — ", 2);
	ft_putnbr_fd(pref + pos + 1, 2);
	ft_putstr_fd(" \n", 2);
}
