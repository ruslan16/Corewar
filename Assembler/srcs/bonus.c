/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 23:47:30 by sirvin            #+#    #+#             */
/*   Updated: 2020/11/26 00:01:43 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

void		error_output(t_champion **champ)
{
	int		count;
	t_error	*error;

	count = 0;
	if (!champ)
		return ;
	error = (*champ)->errors;
	while (error && count < 20)
	{
		ft_printf("Line %d) \"%s\" has Error : <%s>\n",
			error->line_nb, error->line, error->description);
		error = error->next;
		count++;
	}
}

static int	init_error(t_error **error)
{
	if (!(*error = (t_error*)malloc(sizeof(t_error))))
		return (0);
	(*error)->description = NULL;
	(*error)->line = NULL;
	(*error)->line_nb = 0;
	(*error)->next = NULL;
	return (1);
}

int			add_error(char *line, char *msg, int line_nb, t_error **err_list)
{
	t_error	*error;
	t_error *tmp;
	int		count;

	count = 0;
	if (!init_error(&error))
		return (0);
	error->line = line;
	error->description = msg;
	error->line_nb = line_nb;
	if (!*err_list)
		*err_list = error;
	else
	{
		tmp = *err_list;
		while (tmp->next)
		{
			count++;
			tmp = tmp->next;
		}
		tmp->next = error;
	}
	return (1);
}
