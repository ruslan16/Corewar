/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:30:59 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/06 17:31:01 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

void	help(void)
{
	ft_printf("Use *.cor files for disassembling\n");
}

/*
** Check file extension and presence of a name
*/

t_bool	check_filename(const char *file, const char *ext)
{
	if (file && ext && ft_strlen(file) >= ft_strlen(ext))
		return (!ft_strcmp(ft_strchr(file, '\0') - ft_strlen(ext), ext));
	else
		return (false);
}

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

/*
** open check, initialization, parse and get data to structure,
** check name length, check comment length,
** recode champion's exec code, change file extension, write file
*/

void	dsm(char *file)
{
	int			fd;
	t_parser	*parser;

	if ((fd = open(file, O_RDONLY)) == -1)
		terminate(ERR_OPEN_FILE);
	parser = init_bytecode_parser(fd);
	parse_bytecode(parser);
	check_name(parser);
	check_comment(parser);
	process_exec_code(parser);
	file = replace_extension(file, ".cor", ".s");
	if ((fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		terminate(ERR_CREATE_FILE);
	write_dsm_file(fd, parser);
	ft_printf("Writing output program to %s\n", file);
	ft_strdel(&file);
	free_bytecode_parser(&parser);
}

/*
** Check correct filename - if not, print "Help" (see above),
** if yes - proceed to disassemble (dsm)
*/

int		main(int ac, char **av)
{
	errno = 0;
	if (ac == 2 && check_filename(av[1], ".cor"))
		dsm(av[1]);
	else
		help();
	return (0);
}
