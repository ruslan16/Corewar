/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:31:51 by sirvin            #+#    #+#             */
/*   Updated: 2020/11/24 23:38:12 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

char		*get_path(char *name)
{
	char	*tmp;
	char	*path;

	path = name;
	while ((tmp = ft_strchr(name, '/')))
		name = ++tmp;
	while ((tmp = ft_strchr(name, '.')))
		name = ++tmp;
	*(name - 1) = '\0';
	name = ft_strjoin(path, ".cor");
	return (name);
}

int			create_file(t_champion *champ, t_op *op, char *name)
{
	int		fd;
	int		ret;

	name = get_path(name);
	ret = 1;
	if (ret && (fd = open(name, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR
	| S_IRGRP | S_IROTH)) == -1)
		ret = 0;
	if (!ret)
	{
		ft_strdel(&name);
		return (0);
	}
	translate_line(fd, champ, op);
	ft_printf("Writing to %s\n", name);
	ft_strdel(&name);
	return (1);
}

int			open_file(char *argv)
{
	char	*str;
	char	*temp;
	int		fd;

	temp = argv;
	while ((str = ft_strchr(temp, '/')))
		temp = ++str;
	while ((str = ft_strchr(temp, '.')))
		temp = ++str;
	if (!ft_strequ(temp, "s"))
	{
		write(2, "This type is incorrect\n", 23);
		return (-1);
	}
	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		write(2, "Can`t open file\n", 16);
		return (-1);
	}
	return (fd);
}
