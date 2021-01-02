/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:42:45 by sirvin            #+#    #+#             */
/*   Updated: 2020/12/12 00:00:12 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_ASM_H
# define COREWAR_ASM_H

# include "../../libft/includes/libft.h"
# include "../system/op.h"
# include "unistd.h"
# include "stdlib.h"
# include "../../libft/includes/ft_printf.h"

typedef struct		s_op
{
	char			*opname;
	int				param_count;
	int				param_type[3];
	int				opcode;
	int				cycles;
	char			*description;
	int				acb;
	int				half_size;
}					t_op;

extern t_op			g_op_tab[17];

typedef struct		s_line
{
	char			*opname;
	int				opcode;
	char			*param[3];
	int				param_type[3];
	int				param_count;
	t_list			*bytecode;
	struct s_line	*next;
	struct s_line	*last;
}					t_line;

typedef struct		s_label
{
	char			*name;
	int				dist;
	char			*line;
	int				line_nb;
	int				used;
	struct s_label	*next;
}					t_label;

typedef struct		s_error
{
	char			*description;
	char			*line;
	int				line_nb;
	struct s_error	*next;
}					t_error;

typedef struct		s_champion
{
	t_header		*header;
	t_line			*lines;
	t_label			*arg_label;
	t_label			*label;
	size_t			bytecount;
	t_error			*errors;
	int				name;
	int				comt;
}					t_champion;

int					read_next(const int fd, char **line, char c);
void				put(char buff, char **line, size_t size);
int					open_file(char *argv);
int					read_file(int fd, t_champion *champ);
int					create_file(t_champion *champ, t_op *op, char *name);

char				*parse_line(char *s, t_champion *champ, int nb);
char				*parse_line_two(t_champion *champ, char *str, int line_nb);
char				*pars_header(char *s, int name, t_champion *champ);
char				*parse_operation(char *s, t_champion *champ);

char				*get_label(char **s, char **label);
char				*get_opname(char **s, char **opname);
char				*get_arguments(char *s, t_line *line);
int					get_type_arg(char *s);
int					get_opcode(char *opname);
char				get_acb_byte(t_line *line);
int					get_count_bytes(int param_type, int half);
void				get_arg_byte(t_line *line, int nb, int half, t_label *lab);

char				*add_header(char *tmp, int name, t_champion *champ);
char				*add_label(char *name, int dist, t_champion **champ);
char				*add_arg_label(char *name, t_champion **champ,
					char *str, int nb);
void				add_line(t_line *line, t_champion *champ);
int					add_bytecode(t_list **bytecode, char c);

char				*init_line(t_line **line);
char				*init_label(t_label **label, char *name,
					int dist, char *str);
int					init_champ(t_champion **champ);

int					count_arg(char **arg);
int					check_is_empty(char *str);

int					translate_opname(t_line *line, t_op op, t_champion *champ);
void				translate_line(int fd, t_champion *champ, t_op *op);

void				free_champ(t_champion **champs);
void				free_label(t_label **labels);
void				free_lines(t_line **lines);
void				free_errors(t_error **errors);
void				struct_del(void *el, size_t el_size);

int					fill_label(t_label *arg_lab,
				t_label *lab, t_error **error);

int					add_error(char *line, char *msg,
				int line_nb, t_error **err_list);
void				error_output(t_champion **champ);

#endif
