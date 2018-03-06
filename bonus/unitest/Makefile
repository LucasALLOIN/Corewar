##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## root makefile
##

#_-_-_-_-_-_-_-_-_-_-_-_VAR_-_-_-_-_-_-_-_-_-_-_-_-_#


ASM_DIR		=	../../asm

ASM_COMPILE	=	./asm

ASM		=	asm


#-_-_-_-_-_-_-_-_-_-_-_RULES-_-_-_-_-_-_-_-_-_-_-_-_#

all:	$(ASM_COMPILE)/$(ASM)

$(ASM_COMPILE)/$(ASM):
			@make --no-print-directory -C $(ASM_DIR) re
			@cp $(ASM_DIR)/asm $@

clean:
			@make --no-print-directory -C $(ASM_DIR) clean

fclean:
			@make --no-print-directory -C $(ASM_DIR) fclean
			@rm -f $(ASM_COMPILE)/$(ASM)

re:	fclean all

.PHONY:	re	clean	fclean	test_run test_clear all docker
