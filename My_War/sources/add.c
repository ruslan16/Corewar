/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:53:16 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/06 16:53:18 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

void	add_stmnt(t_statement **list, t_statement *new)
{
	t_statement *state;

	if (list)
	{
		if (*list)
		{
			state = *list;
			while (state->next)
				state = state->next;
			state->next = new;
		}
		else
			*list = new;
	}
}
