/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:03:00 by nsance            #+#    #+#             */
/*   Updated: 2021/01/08 22:48:18 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <inttypes.h>
# include "op.h"

# define MAX_INST_SIZE 32

typedef struct s_process	t_process;

struct	s_process
{
	int			champ_id;
	uint32_t	reg[REG_NUMBER];
	int			pc;
	int			carry;
	int			queued_op;
	int			cycles_left;
	int			lives;
	int			last_live;
};

#endif
