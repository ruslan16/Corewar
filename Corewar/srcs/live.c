/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:35:32 by nsance            #+#    #+#             */
/*   Updated: 2021/01/08 23:24:40 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "corewar.h"
#include "process.h"
#include "champion.h"
#include "func_op.h"
#include "op.h"

static void	live_champ(t_env *env, t_champ *champ)
{
	champ->live_cycle = env->cur_cycle;
	champ->lives += 1;
	if (env->visu != VISU_ON)
		ft_printf("Champion %d (\"%s\") is alive\n", champ->id
				, champ->header.prog_name);
}

int			live(t_env *env, t_process *cur_process, uint8_t *bytes)
{
	int			ret;
	t_decode	decode;
	t_list		*champ;

	fill_decode(env, cur_process, &decode, 1);
	ret = decode_args(&decode, bytes + 1, DIR_CODE << 6, REG_DIR) + 1;
	champ = env->champ_lst;
	while (champ != NULL)
	{
		if (((t_champ *)champ->content)->id == (int)decode.tab[0].value)
		{
			live_champ(env, (t_champ *)champ->content);
			break ;
		}
		champ = champ->next;
	}
	cur_process->lives += 1;
	cur_process->last_live = env->cur_cycle;
	return (ret);
}
