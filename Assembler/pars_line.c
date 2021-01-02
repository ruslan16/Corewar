/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:11:46 by sirvin            #+#    #+#             */
/*   Updated: 2020/12/17 20:25:11 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm/asm.h"

char		*parse_operation(char *s, t_champion *champ)
{
	t_line	*line;
	char	*tmp;
	char	*ret;

	ret = NULL;
	line = NULL;
	if (!(s = ft_strtrim(s)))
		return (NULL);
	if (s[ft_strlen(s) - 1] == SEPARATOR_CHAR)
		ret = ft_strdup("Separator char at the end of the line");
	tmp = s;
	ret = (!ret) ? init_line(&line) : ret;
	ret = (!ret) ? get_opname(&s, &line->opname) : ret;
	ret = (!ret) ? get_arguments(s, line) : ret;
	ft_strdel(&tmp);
	if (!ret)
		add_line(line, champ);
	else
		free_lines(&line);
	return (ret);
}

char		*parse_label(char *s, t_champion *champ)
{
	char	*tmp;
	char	*ret;
	char	*label;

	ret = NULL;
	label = NULL;
	if ((tmp = ft_strchr(s, COMMENT_CHAR)))
		tmp[0] = '\0';
	else if ((tmp = ft_strchr(s, ALT_COMMENT)))
		tmp[0] = '\0';
	ret = get_label(&s, &label);
	if (label)
	{
		add_label(label, champ->bytecount, &champ);
		ft_strdel(&label);
	}
	if (!ret && *s)
		ret = parse_operation(s, champ);
	return (ret);
}

char		*pars_header(char *s, int name, t_champion *champ)
{
	int		i;
	char	*tmp;

	i = (name) ? ft_strlen(NAME_CMD_STRING) : ft_strlen(COMMENT_CMD_STRING);
	while (ft_isspace(s[i]))
		i++;
	if (s[i++] != '"')
		return (ft_strdup("Name and comment must be inside quotes"));
	s = s + i;
	if (!(tmp = ft_strchr(s, '"')))
		return (ft_strdup("Quotes must close in the same line"));
	tmp++;
	while (ft_isspace(*tmp))
		tmp++;
	if (*tmp != '\0' && *tmp != COMMENT_CHAR && *tmp != ALT_COMMENT)
		return (ft_strdup("Invalid characters at the end of the line"));
	s[ft_strlen(s) - ft_strlen(ft_strchr(s, '"'))] = '\0';
	return (add_header(s, name, champ));
}

char		*parse_line_two(t_champion *champ, char *str, int line_nb)
{
	t_line	*line;
	int		i;

	if ((!(i = 0) && !champ->lines) || check_is_empty(str))
		return (NULL);
	line = champ->lines->last;
	if (!line || !(line->opcode = get_opcode(line->opname)))
		return (ft_strdup("Operation name does not match any operation"));
	if (line->param_count != g_op_tab[line->opcode - 1].param_count)
		return (ft_strdup("Invalid number of params for this operation"));
	while (i < line->param_count)
	{
		if ((line->param_type[i] & g_op_tab[line->opcode - 1].param_type[i])
			!= line->param_type[i])
			return (ft_strdup("Argument type does not match"));
		if (ft_strchr(line->param[i++], LABEL_CHAR))
			add_arg_label(ft_strchr(line->param[i - 1], LABEL_CHAR) + 1,
							&champ, str, line_nb);
	}
	if (!translate_opname(line, g_op_tab[line->opcode - 1], champ))
		return (ft_strdup("Failed to allocate bytecode"));
	return (NULL);
}

char		*parse_line(char *s, t_champion *champ, int nb)
{
	char	*str;
	char	*ret;

	if (!s)
		return (NULL);
	if (!(str = ft_strtrim(s)))
		return (ft_strdup("Failed to malloc trimmed line"));
	ret = NULL;
	if (!champ->lines && ft_strncmp(str, NAME_CMD_STRING,
									ft_strlen(NAME_CMD_STRING)) == 0)
		ret = pars_header(str, 1, champ);
	else if (!champ->lines && ft_strncmp(str, COMMENT_CMD_STRING,
										ft_strlen(COMMENT_CMD_STRING)) == 0)
		ret = pars_header(str, 0, champ);
	else if (*str != '\0' && *str != COMMENT_CHAR && *str != ALT_COMMENT)
	{
		if (!champ->lines && (!champ->header || !champ->name ||
							!champ->comt))
			add_error(ft_strdup(s), ft_strdup("No name or comment"), nb,
					&champ->errors);
		ret = parse_label(str, champ);
	}
	ft_strdel(&str);
	return (ret);
}
