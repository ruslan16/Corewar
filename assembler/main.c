/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 18:37:11 by sirvin            #+#    #+#             */
/*   Updated: 2020/12/11 23:38:25 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

int				main(int argc, char **argv)
{
	int			fd;
	t_champion	*champ;

	if (argc != 2)
		return (write(2, "Too many arguments\n", 19));
	if ((fd = open_file(argv[1])) == -1)
		return (write(2, "Can`t open file\n", 16));
	if (!init_champ(&champ))
		return (write(2, "Error malloc\n", 13));
	if (!read_file(fd, champ))
		fill_label(champ->arg_label, champ->label, &champ->errors);
	if (close(fd) == -1)
		return (write(2, "Can`t close file\n", 17));
	if (!champ->errors)
	{
		if (!champ->lines)
			return (write(2, "File is empty\n", 14));
		if (!create_file(champ, g_op_tab, argv[1]))
			return (write(2, "Error while create or translate file\n", 37));
	}
	else
		error_output(&champ);
	free_champ(&champ);
	return (1);
}
