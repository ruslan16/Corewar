/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:50:28 by sirvin            #+#    #+#             */
/*   Updated: 2020/11/23 22:11:30 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

int			read_file(int fd, t_champion *champ)
{
	char	*str;
	int		ret;
	int		line_nb;
	char	*err_msg;
	int		nb;

	ret = 0;
	line_nb = 1;
	while ((nb = read_next(fd, &str, '\n')))
	{
		if ((err_msg = parse_line(str, champ, line_nb)))
			ret += add_error(ft_strdup(str), err_msg, line_nb, &champ->errors);
		else if (str && (err_msg = parse_line_two(champ, str, line_nb)))
			ret += add_error(ft_strdup(str), err_msg, line_nb, &champ->errors);
		ft_strdel(&str);
		line_nb++;
		if (ret >= 21)
			return (ret);
	}
	if (str && str[0] != '\0' && ++ret)
		add_error(ft_strdup(str), ft_strdup("No empty line at end of file"),
				line_nb, &champ->errors);
	ft_strdel(&str);
	return (ret);
}
