/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 05:42:03 by nsance            #+#    #+#             */
/*   Updated: 2021/01/08 22:47:57 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define OPT_NOARG 0
# define OPT_MUSTHAVEARG 1

# include "corewar.h"

typedef struct	s_opt
{
	const char	*name;
	t_error		(*fn)(t_env *, const char *);
	int			optarg_type;
}				t_opt;

t_error			parse_opt(t_env *env, t_opt *opts, char **argv, int *cur_arg);
t_error			parse_opts(t_env *env, char **argv, int *cur_arg);

#endif
