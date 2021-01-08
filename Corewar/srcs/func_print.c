/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 03:14:43 by nsance            #+#    #+#             */
/*   Updated: 2021/01/08 23:23:08 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ncurses.h>
#include "corewar.h"
#include "visual.h"

t_data	g_data;

void		loop_screen(void)
{
	int	ch;

	nodelay(g_data.win, FALSE);
	while ((ch = getch()))
	{
		if (ch == 27)
		{
			delwin(g_data.hud);
			endwin();
			break ;
		}
	}
}

int			champ_color(int id)
{
	int	idx;

	idx = 0;
	while (idx < MAX_PLAYERS)
	{
		if (id == g_data.champ[idx])
			return (idx + 1);
		idx++;
	}
	return (0);
}

void		print_bottom(void)
{
	t_int2	dim;

	getmaxyx(g_data.hud, dim.y, dim.x);
	mvwprintw(g_data.hud, dim.y - 8, X_HUD_PADD
			, "   ___");
	mvwprintw(g_data.hud, dim.y - 7, X_HUD_PADD
			, "  / __\\___  _ __ _____      ____ _ _ __ ");
	mvwprintw(g_data.hud, dim.y - 6, X_HUD_PADD
			, " / /  / _ \\| '__/ _ \\ \\ /\\ / / _` | '__|");
	mvwprintw(g_data.hud, dim.y - 5, X_HUD_PADD
			, "/ /__| (_) | | |  __/\\ V  V / (_| | |");
	mvwprintw(g_data.hud, dim.y - 4, X_HUD_PADD
			, "\\____/\\___/|_|  \\___| \\_/\\_/ \\__,_|_|");
	mvwprintw(g_data.hud, dim.y - 7, dim.x - 12, "nsance");
	mvwprintw(g_data.hud, dim.y - 6, dim.x - 12, "rvalenti");
	mvwprintw(g_data.hud, dim.y - 5, dim.x - 12, "vifonne");
	mvwprintw(g_data.hud, dim.y - 4, dim.x - 12, "wta");
}
