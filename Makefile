
all	:
	@$(MAKE) --no-print-directory -C Corewar
	@$(MAKE) --no-print-directory -C Assembler
	@cp -a ./Corewar/corewar ./
	@cp -a ./Assembler/asm ./
	@printf "$(GRN)Corewar, Assembler compiled$(EOC)\n"

dsm	:
	@$(MAKE) --no-print-directory -C Bonus
	@cp -a ./Bonus/dsm ./

clean	:
	@$(MAKE) --no-print-directory -C Corewar clean
	@$(MAKE) --no-print-directory -C Assembler clean
	@$(MAKE) --no-print-directory -C Bonus clean
	@printf "$(RED)Corewar, Assembler cleaned$(EOC)\n"

fclean	:	clean
	@$(MAKE) --no-print-directory -C Corewar fclean
	@$(MAKE) --no-print-directory -C Assembler fclean
	@$(MAKE) --no-print-directory -C Bonus fclean
	rm -f ./corewar
	rm -f ./asm
	rm -f ./dsm
	@printf "$(RED)Corewar, Assembler removed$(EOC)\n"

re	:	fclean
	@$(MAKE) --no-print-directory -C Corewar re
	@$(MAKE) --no-print-directory -C Assembler re
	@printf "$(RED)Corewar, Assembler recompiled$(EOC)\n"

.PHONY: all clean fclean re

GRN =	\033[0;32m
RED =	\033[0;31m
EOC =	\033[0m
