
all	:
	@$(MAKE) --no-print-directory -C Corewar
	@$(MAKE) --no-print-directory -C Assembler
	@cp -a ./Corewar/corewar ./
	@cp -a ./Assembler/asm ./
	@printf "$(GRN)Corewar, Assembler compiled$(EOC)\n"

clean	:
	@$(MAKE) --no-print-directory -C Corewar clean
	@$(MAKE) --no-print-directory -C Assembler clean
	@printf "$(RED)Corewar, Assembler cleaned$(EOC)\n"

fclean	:	clean
	@$(MAKE) --no-print-directory -C Corewar fclean
	@$(MAKE) --no-print-directory -C Assembler fclean
	rm -f ./corewar
	rm -f ./asm
	@printf "$(RED)Corewar, Assembler removed$(EOC)\n"

re	:	fclean
	@$(MAKE) --no-print-directory -C Corewar re
	@$(MAKE) --no-print-directory -C Assembler re
	@printf "$(RED)Corewar, Assembler recompiled$(EOC)\n"

.PHONY: all clean fclean re

GRN =	\033[0;32m
RED =	\033[0;31m
EOC =	\033[0m
