/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:32:41 by nsance            #+#    #+#             */
/*   Updated: 2021/01/08 22:47:37 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAMPION_H
# define CHAMPION_H

# include "op.h"

typedef struct	s_champ
{
	t_header		header;
	unsigned char	prog[CHAMP_MAX_SIZE];
	int				live_cycle;
	int				lives;
	int				id;
}				t_champ;

#endif
