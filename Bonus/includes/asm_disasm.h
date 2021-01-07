/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_disasm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:27:03 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/05 12:27:14 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_DISASM_H

# define ASM_DISASM_H

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include "asm_disasm.h"
# include "../libft/includes/ft_printf.h"
# include "asm_error.h"
# include "op.h"
# include "asm_op.h"
# include "../libft/includes/libft.h"

# define INDEX(X) ((X) - 1)

typedef struct			s_statement
{
	t_op				*op;
	uint8_t				args_types[3];
	int32_t				args[3];
	struct s_statement	*next;
}						t_statement;

typedef struct			s_parser
{
	int					fd;
	char				*name;
	char				*comment;
	int32_t				code_size;
	uint8_t				*code;
	int32_t				pos;
	t_statement			*statements;
}						t_parser;

void					add_stmnt(t_statement **list, t_statement *new);
void					process_arg_types(t_parser *parser,
											t_statement *statement);
int32_t					bytecode_to_int32(const uint8_t *byte, size_t size);
void					parse_bytecode(t_parser *parser);
void					check_name(t_parser *parser);
void					check_comment(t_parser *parser);
void					check_types_code(t_parser *parser,
									int8_t args_types_code, int all_args);
t_bool					is_arg_types_valid(t_statement *statement);
void					process_exec_code(t_parser *parser);
void					name_warning(size_t pos);
void					comment_warning(size_t pos);
void					types_code_warning(size_t pos);
void					op_code_error(t_parser *parser);
void					arg_types_code_error(t_parser *parser);
void					length_error(t_parser *parser);
void					register_error(t_parser *parser);
void					write_dsm_file(int fd, t_parser *parser);
void					free_bytecode_parser(t_parser **parser);
t_parser				*init_bytecode_parser(int fd);
t_statement				*init_statement(void);
char					*replace_extension(char *file, char *old, char *new);
void					help(void);
t_bool					check_filename(const char *file, const char *ext);
void					terminate(char *s);
void					dsm(char *file);

#endif
