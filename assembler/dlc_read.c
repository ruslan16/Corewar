/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:51:32 by sirvin            #+#    #+#             */
/*   Updated: 2020/11/23 20:51:32 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

void			put(char buff, char **line, size_t size)
{
	char		*tmp;

	tmp = *line;
	*line = ft_strnew(size);
	if (tmp)
		ft_strcpy(*line, tmp);
	(*line)[size - 1] = buff;
	if (tmp)
		free(tmp);
}

int				read_next(const int fd, char **line, char c)
{
	char		buff;
	ssize_t		res;
	size_t		size;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	size = 0;
	while ((res = read(fd, &buff, 1)) > 0)
	{
		if (buff == c)
			return (1);
		put(buff, line, ++size);
	}
	return (0);
}
