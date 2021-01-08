/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 00:05:44 by nsance            #+#    #+#             */
/*   Updated: 2021/01/08 23:27:15 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include "visual.h"

t_data		g_data;

static void	end_ncurses(int sig)
{
	delwin(g_data.hud);
	endwin();
	ft_lstfree(&g_data.env->champ_lst);
	ft_lstfree(&g_data.env->process_lst);
	exit(sig);
}

void		sig_handler(void)
{
	signal(SIGABRT, end_ncurses);
	signal(SIGFPE, end_ncurses);
	signal(SIGILL, end_ncurses);
	signal(SIGINT, end_ncurses);
	signal(SIGSEGV, end_ncurses);
	signal(SIGTERM, end_ncurses);
}
