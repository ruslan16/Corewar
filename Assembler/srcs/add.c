/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:36:31 by sirvin            #+#    #+#             */
/*   Updated: 2020/12/11 23:55:53 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

int				add_bytecode(t_list **bytecode, char c)
{
	t_list		*tmp;
	t_list		*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (0);
	new->content = ft_strdup(&c);
	new->content_size = 1;
	new->next = NULL;
	tmp = *bytecode;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*bytecode = new;
	return (1);
}

void			add_line(t_line *line, t_champion *champ)
{
	t_line		*tmp;

	if (!champ->lines)
		champ->lines = line;
	else
	{
		tmp = champ->lines->last;
		tmp->next = line;
	}
	champ->lines->last = line;
}

char			*add_arg_label(char *name,
					t_champion **champ, char *str, int nb)
{
	t_label		*label;
	t_label		*tmp;
	char		*ret;

	if ((ret = init_label(&label, ft_strdup(name),
						(*champ)->bytecount, ft_strdup(str))))
		return (ret);
	label->line_nb = nb;
	if (!(*champ)->arg_label)
		(*champ)->arg_label = label;
	else
	{
		tmp = (*champ)->arg_label;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = label;
	}
	return (NULL);
}

char			*add_label(char *name, int dist, t_champion **champ)
{
	t_label		*label;
	t_label		*tmp;
	char		*ret;

	if ((ret = init_label(&label, ft_strdup(name), dist, NULL)))
		return (ret);
	if (!(*champ)->label)
		(*champ)->label = label;
	else
	{
		tmp = (*champ)->label;
		while (tmp->next)
		{
			if (!ft_strcmp(tmp->name, label->name) ||
				!ft_strcmp(tmp->next->name, label->name))
			{
				free_label(&label);
				return (ft_strdup("Double declaration of label"));
			}
			tmp = tmp->next;
		}
		tmp->next = label;
	}
	return (NULL);
}

char			*add_header(char *tmp, int name, t_champion *champ)
{
	t_header	*head;

	head = champ->header;
	if (name)
	{
		if (ft_strlen(tmp) > PROG_NAME_LENGTH || head->prog_name[0])
			return (ft_strdup("Name is duplicated or too big"));
		ft_strcpy(head->prog_name, tmp);
		champ->name = 1;
	}
	else
	{
		if (ft_strlen(tmp) > COMMENT_LENGTH || head->comment[0])
			return (ft_strdup("Comment is duplicated or too big"));
		ft_strcpy(head->comment, tmp);
		champ->comt = 1;
	}
	return (NULL);
}
