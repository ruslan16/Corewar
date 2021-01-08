/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:01:13 by nsance            #+#    #+#             */
/*   Updated: 2021/01/08 22:49:55 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <ncurses.h>
# include "corewar.h"

# define HUD_COL		250
# define WIDTH			64
# define HEIGHT			64
# define X_PADD			27
# define Y_PADD			9
# define X_HUD_PADD		4
# define Y_HUD_PADD		2
# define TXT_HUD_PADD	5
# define SPEED			50000
# define MAX_SPEED		1000000
# define MIN_SPEED		500
# define SPEED_INC		3000

typedef struct	s_int2
{
	int			x;
	int			y;
}				t_int2;

typedef struct	s_data
{
	t_env		*env;
	WINDOW		*win;
	WINDOW		*hud;
	int			champ[MAX_PLAYERS];
	int			time;
	t_int2		cursor;
}				t_data;

extern t_data	g_data;

#endif
