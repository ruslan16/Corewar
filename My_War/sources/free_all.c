/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:23:55 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/06 17:23:57 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

/*
** free everything
*/

static void	free_statements(t_statement **list)
{
	t_statement	*current;
	t_statement	*delete;

	current = *list;
	while (current)
	{
		delete = current;
		current = current->next;
		ft_memdel((void **)&delete);
	}
	*list = NULL;
}

void		free_bytecode_parser(t_parser **parser)
{
	ft_strdel(&((*parser)->name));
	ft_strdel(&((*parser)->comment));
	ft_memdel((void **)&((*parser)->code));
	free_statements(&((*parser)->statements));
	ft_memdel((void **)parser);
}
