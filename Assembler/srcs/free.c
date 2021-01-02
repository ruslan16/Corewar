/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 23:12:51 by sirvin            #+#    #+#             */
/*   Updated: 2020/12/11 23:55:53 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

void			struct_del(void *el, size_t el_size)
{
	if (!el)
		return ;
	free(el);
	(void)el_size;
}

void			free_errors(t_error **errors)
{
	t_error		*tmp;
	t_error		*error;

	error = *errors;
	while (error)
	{
		tmp = error;
		if (error->description)
			ft_strdel(&error->description);
		if (error->line)
			ft_strdel(&error->line);
		error = error->next;
		free(tmp);
	}
	*errors = NULL;
}

void			free_lines(t_line **lines)
{
	t_line		*line;
	t_line		*tmp;
	int			i;

	line = *lines;
	while (line != NULL)
	{
		i = 0;
		if (line->opname)
			ft_strdel(&line->opname);
		while (i < 3)
		{
			if (line->param[i])
				ft_strdel(&line->param[i]);
			i++;
		}
		if (line->bytecode)
			ft_lstdel(&line->bytecode, &struct_del);
		tmp = line;
		line = line->next;
		free(tmp);
	}
	*lines = NULL;
}

void			free_label(t_label **labels)
{
	t_label		*label;
	t_label		*tmp;

	label = *labels;
	while (label)
	{
		tmp = label;
		if (label->name)
			ft_strdel(&label->name);
		if (label->line)
			ft_strdel(&label->line);
		label = label->next;
		free(tmp);
	}
	*labels = NULL;
}

void			free_champ(t_champion **champs)
{
	t_champion	*champ;

	champ = *champs;
	if (champ->header)
		free(champ->header);
	if (champ->lines)
		free_lines(&champ->lines);
	if (champ->errors)
		free_errors(&champ->errors);
	if (champ->label)
		free_label(&champ->label);
	if (champ->arg_label)
		free_label(&champ->arg_label);
	free(champ);
	*champs = NULL;
}
