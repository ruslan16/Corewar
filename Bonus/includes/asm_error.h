/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:28:43 by tmlkshk           #+#    #+#             */
/*   Updated: 2021/01/05 12:28:48 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_ERROR_H

# define ASM_ERROR_H

# define ERR_STR_INIT			"ERROR: Can\'t initialize string"

# define ERR_PARSER_INIT		"ERROR: Can\'t initialize parser"

# define ERR_MENTION_INIT		"ERROR: Can\'t initialize mention"

# define ERR_STATEMENT_INIT		"ERROR: Can\'t initialize statement"

# define ERR_OPEN_FILE			"ERROR: Can\'t open file with champion"

# define ERR_READ_FILE			"ERROR: Can\'t read file with champion"

# define ERR_CREATE_FILE		"ERROR: Can\'t create file"

# define ERR_INVALID_FILE		"ERROR: Invalid file with champion"

# define ERR_INVALID_MAGIC		"ERROR: Invalid magic header"

# define ERR_NO_NULL			"ERROR: No null control bytes"

# define ERR_CODE_INIT			"ERROR: Can\'t initialize string of code"

# define ERR_INVALID_CODE_SIZE	"ERROR: Invalid code size"

# include "asm_disasm.h"

#endif
