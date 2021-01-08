/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 03:11:42 by nsance            #+#    #+#             */
/*   Updated: 2021/01/08 23:21:02 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <ncurses.h>
#include "corewar.h"
#include "visual.h"

t_data	g_data;

void	init_champ_color(void)
{
	init_pair(0, -1, -1);
	init_pair(1, COLOR_RED, -1);
	init_pair(2, COLOR_BLUE, -1);
	init_pair(3, COLOR_GREEN, -1);
	init_pair(4, COLOR_YELLOW, -1);
	init_pair(5, -1, COLOR_RED);
	init_pair(6, -1, COLOR_BLUE);
	init_pair(7, -1, COLOR_GREEN);
	init_pair(8, -1, COLOR_YELLOW);
}

void	print_init_state(t_env *env)
{
	t_int2	cursor;
	t_int2	pos;

	(void)env;
	init_champ_color();
	cursor = (t_int2) {X_PADD, Y_PADD};
	pos = (t_int2) {0, 0};
	while (pos.y < HEIGHT)
	{
		cursor.x = X_PADD;
		pos.x = 0;
		while (pos.x < WIDTH)
		{
			mvwprintw(g_data.win, cursor.y, cursor.x, "00 ");
			cursor.x += 3;
			pos.x += 1;
		}
		cursor.y += 1;
		pos.y += 1;
	}
}
