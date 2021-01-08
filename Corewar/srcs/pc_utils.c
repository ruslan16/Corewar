/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:48:17 by nsance            #+#    #+#             */
/*   Updated: 2021/01/08 23:19:29 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	fix_pc_offset(int *offset)
{
	while (*offset < 0)
		*offset += MEM_SIZE;
	if (*offset >= MEM_SIZE)
		*offset %= MEM_SIZE;
}

void	increase_pc(t_process *process, int value)
{
	process->pc += value;
	fix_pc_offset(&process->pc);
}
