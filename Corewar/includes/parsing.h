/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:57:40 by nsance            #+#    #+#             */
/*   Updated: 2021/01/08 22:48:47 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H
# define BUFF_SIZ 4096

# include "champion.h"
# include "process.h"
# include "corewar.h"

int	read_file(const char *filename, t_champ *champ);

#endif
