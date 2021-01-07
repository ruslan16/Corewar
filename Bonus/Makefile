# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 17:53:10 by tmlkshk           #+#    #+#              #
#    Updated: 2021/01/06 17:53:16 by tmlkshk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DSM_NAME = dsm

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3

# Libraries and Includes

DSM_LIBRARIES = -lftprintf -L$(FT_PRINTF_DIRECTORY)
DSM_INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\
	-I$(FT_PRINTF_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./ft_printf/libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

FT_PRINTF = $(FT_PRINTF_DIRECTORY)libftprintf.a
FT_PRINTF_DIRECTORY = ./ft_printf/
FT_PRINTF_HEADERS = $(FT_PRINTF_DIRECTORY)includes/

# Headers

HEADERS_DIRECTORY = ./includes/

# dsm

DSM_HEADERS_LIST = \
	op.h\
	asm_error.h\
	asm_op.h\
	asm_disasm.h
DSM_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(DSM_HEADERS_LIST))

# Sources

# dsm

DSM_SOURCES_DIRECTORY = ./sources/
DSM_SOURCES_LIST = \
	add.c\
	arguments.c\
	byte_parce.c\
	check.c\
	code_main.c\
	err_mess.c\
	errs.c\
	file_write.c\
	free_all.c\
	initial_and_extens.c\
	main.c

DSM_SOURCES = $(addprefix $(DSM_SOURCES_DIRECTORY), $(DSM_SOURCES_LIST))

# Objects

OBJECTS_DIRECTORY = ./objects/

# dsm

DSM_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)dsm/
DSM_OBJECTS_LIST = $(patsubst %.c, %.o, $(DSM_SOURCES_LIST))
DSM_OBJECTS	= $(addprefix $(DSM_OBJECTS_DIRECTORY), $(DSM_OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(DSM_NAME)

$(DSM_NAME): $(FT_PRINTF) $(DSM_OBJECTS_DIRECTORY) $(DSM_OBJECTS)
	@$(CC) $(FLAGS) $(DSM_LIBRARIES) $(DSM_INCLUDES) $(DSM_OBJECTS) -o $(DSM_NAME)
	@echo "\n$(DSM_NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(DSM_NAME): $(GREEN)$(DSM_NAME) was created$(RESET)"

$(DSM_OBJECTS_DIRECTORY):
	@mkdir -p $(DSM_OBJECTS_DIRECTORY)
	@echo "$(DSM_NAME): $(GREEN)$(DSM_OBJECTS_DIRECTORY) was created$(RESET)"

$(DSM_OBJECTS_DIRECTORY)%.o : $(DSM_SOURCES_DIRECTORY)%.c $(DSM_HEADERS)
	@$(CC) $(FLAGS) -c $(DSM_INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(FT_PRINTF):
	@echo "$(DSM_NAME): $(GREEN)Creating $(FT_PRINTF)...$(RESET)"
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY)

clean:
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(DSM_NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(DSM_NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY) fclean
	@echo "$(DSM_NAME): $(RED)$(FT_PRINTF) was deleted$(RESET)"
	@rm -f $(DSM_NAME)
	@echo "$(DSM_NAME): $(RED)$(DSM_NAME) was deleted$(RESET)"
	@rm -f $(DSM_NAME)
	@echo "$(DSM_NAME): $(RED)$(DSM_NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
