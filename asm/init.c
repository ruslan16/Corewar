/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:44:22 by sirvin            #+#    #+#             */
/*   Updated: 2020/11/23 21:52:12 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

char		*init_label(t_label **label, char *name, int dist, char *str)
{
	if (!(*label = (t_label*)malloc(sizeof(t_label))))
		return (ft_strdup("Failed to malloc label declaration"));
	if (!((*label)->name = name))
	{
		free(*label);
		return (ft_strdup("Failed to malloc label declaration name"));
	}
	(*label)->dist = dist;
	(*label)->next = NULL;
	(*label)->line = str;
	(*label)->used = 0;
	return (NULL);
}

char		*init_line(t_line **line)
{
	if (!(*line = (t_line*)malloc(sizeof(t_line))))
		return (ft_strdup("Failed to malloc s_line struct"));
	ft_bzero(*line, sizeof(t_line));
	return (NULL);
}

int			init_champ(t_champion **champ)
{
	if (!(*champ = (t_champion*)malloc(sizeof(**champ))))
		return (0);
	if (!((*champ)->header = (t_header*)malloc(sizeof(t_header))))
	{
		free(*champ);
		return (0);
	}
	ft_bzero(&((*champ)->header->prog_name), PROG_NAME_LENGTH + 1);
	ft_bzero(&((*champ)->header->prog_name), COMMENT_LENGTH + 1);
	(*champ)->header->magic = COREWAR_EXEC_MAGIC;
	(*champ)->lines = NULL;
	(*champ)->arg_label = NULL;
	(*champ)->label = NULL;
	(*champ)->errors = NULL;
	(*champ)->bytecount = 0;
	(*champ)->name = 0;
	(*champ)->comt = 0;
	return (1);
}
