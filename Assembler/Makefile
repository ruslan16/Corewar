NAME = asm

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC_NAME = add.c bonus.c dlc_read.c free.c get_bytes.c get.c get_type_arg.c \
	init.c main.c op.c open_file.c pars_line.c read_file.c translate.c \
	trash_fun.c

SRC_PATH = srcs

OBJ_PATH = objs

OBJ_NAME = $(SRC_NAME:.c=.o)

DEP_NAME = $(SRC_NAME:.c=.d)

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

DEPS = $(addprefix $(OBJ_PATH)/,$(DEP_NAME))

CFLAGS += -I includes

CFLAGS += -I libft/includes

LIBFT = libft

LDLIBS = -lft

LDFLAGS = -L $(LIBFT)

################################################################################
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME_S),Darwin)
	NUMPROC := $(shell sysctl hw.ncpu | awk '{print $$2}')
endif
################################################################################

all	: $(NAME)

fast	:
	@$(MAKE) -s -j$(NUMPROC)

libft.a	:
	@printf "$(RED)Making libft...$(EOC)\n"
	@$(MAKE) --no-print-directory -C $(LIBFT) all

$(OBJ_PATH)     : libft.a
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@printf "$(GRN)Compiling with \"$(CFLAGS)\" :$(EOC)\n"

$(NAME)	: $(OBJS)
	@printf "$(GRN)%-50s$(EOC)\n" "Compilation done"
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@printf "$(GRN)%-50s$(EOC)\n" "$(NAME) done"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@printf "%-50s\r" "$(CC) $@"
	$(CC) $(CFLAGS) -MD -o $@ -c $<

include $(wildcard $(DEPS))

clean	:
	/bin/rm -rf $(OBJ_PATH)
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean
	@printf "$(RED)./$(OBJ_PATH), libft cleaned$(EOC)\n"

fclean	:	clean
	/bin/rm -f $(NAME)
	@printf "$(RED)$(NAME), libft.a removed$(EOC)\n"

ref	:
	/bin/rm -rf $(OBJ_PATH)
	@printf "$(RED)./$(OBJ_PATH), cleaned$(EOC)\n"
	@$(MAKE) --no-print-directory -j$(NUMPROC) $(NAME)

re	:	fclean
	@$(MAKE) --no-print-directory -j$(NUMPROC) $(NAME)

.PHONY: all fast clean fclean re ref

GRN =	\033[0;32m
RED =	\033[0;31m
EOC =	\033[0m
