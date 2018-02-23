##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## root makefile
##

#_-_-_-_-_-_-_-_-_-_-_-_VAR_-_-_-_-_-_-_-_-_-_-_-_-_#

ASM_DIR		=	./asm

COREWAR_DIR	=	./corewar

TEST		=	./bonus/unitest	

COREWAR		=	corewar

ASM		=	asm


#-_-_-_-_-_-_-_-_-_-_-_RULES-_-_-_-_-_-_-_-_-_-_-_-_#

all:	$(COREWAR) $(ASM)

$(COREWAR):
		@printf "\e[32;1m[COMPILING COREWAR]\e[0m\n"
		@make --no-print-directory -C $(COREWAR_DIR) NAME=$(COREWAR) 

$(ASM):
		@printf "\e[32;1m[COMPILING ASM]\e[0m\n"
		@make --no-print-directory -C $(ASM_DIR) NAME=$(ASM)

re:
		@printf "\e[32;1m[RECOMPILING COREWAR]\e[0m\n"
		@printf "\e[32;1m[RECOMPILING ASM]\e[0m\n"
		@make --no-print-directory -C $(COREWAR_DIR) re NAME=$(COREWAR)
		@make --no-print-directory -C $(ASM_DIR) re NAME=$(ASM)

debug:
		@printf "\e[32;1m[COMPILING DEBUG MODE COREWAR]\e[0m\n"
		@printf "\e[32;1m[COMPILING DEBUG MODE ASM]\e[0m\n"
		@make --no-print-directory -C $(COREWAR_DIR) debug NAME=$(COREWAR)
		@make --no-print-directory -C $(ASM_DIR) debug NAME=$(ASM)

clean:
		@printf "\e[32;1m[CLEANING COREWAR]\e[0m\n"
		@printf "\e[32;1m[CLEANING ASM]\e[0m\n"
		@make --no-print-directory -C $(COREWAR_DIR) clean NAME=$(COREWAR)
		@make --no-print-directory -C $(ASM_DIR) clean NAME=$(ASM)

fclean:
		@printf "\e[32;1m[FCLEANING COREWAR]\e[0m\n"
		@printf "\e[32;1m[FCLEANING ASM]\e[0m\n"
		@make --no-print-directory -C $(COREWAR_DIR) fclean NAME=$(COREWAR)
		@make --no-print-directory -C $(ASM_DIR) fclean NAME=$(ASM)

test_run:

test_clear:


.PHONY:	re	clean	fclean	test_run test_clear all docker
