##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for the test
##

#COLOR

GREEN   	=	\e[1;32m

WHITE   	=	\e[0m

ORANGE  	=       \e[1;33m

BLUE		=	\e[1;34m

CYAN		=	\e[96m

RED		=	\e[1;35m

ROOT		=	../../..

ASM_DIR		=	$(ROOT)/asm

COREWAR_DIR	=	$(ROOT)/corewar

TEST_SRC	=	

SRC_ASM 	=	$(SRC_DIR)/main.c                       \                        
			$(SRC_DIR)/asm.c                        \                        
			$(SRC_DIR)/file_splitter.c              \                        
			$(SRC_DIR)/encoders/header.c            \                        
			$(SRC_DIR)/encoders/label_utils.c       \                        
			$(SRC_DIR)/encoders/code.c              \                        
			$(SRC_DIR)/encoders/asm_utils.c         \                        
			$(SRC_DIR)/encoders/op_encoder.c        \                        
			$(SRC_DIR)/utils/my_calloc.c            \                        
			$(SRC_DIR)/utils/my_atoi.c              \                        
			$(SRC_DIR)/utils/my_strlen.c            \                        
			$(SRC_DIR)/utils/free_it.c              \                        
			$(SRC_DIR)/utils/get_next_line.c        \                        
			$(SRC_DIR)/utils/match.c                \                        
			$(SRC_DIR)/utils/clean_str.c            \                        
			$(SRC_DIR)/utils/get_file.c             \                        
			$(SRC_DIR)/utils/concatenation.c        \                        
			$(SRC_DIR)/utils/find_char.c            \                        
			$(SRC_DIR)/utils/split_text.c 

SRC_COREWAR	=	$(COREWAR_DIR)/core/core.c                    	  \                
                  	$(COREWAR_DIR)/main.c	              	          \                
                  	$(COREWAR_DIR)/utils/my_calloc.c                  \                
                  	$(COREWAR_DIR)/utils/str_utils.c                  \                
	                $(COREWAR_DIR)/bin_parser/parser.c                \                
	                $(COREWAR_DIR)/utils/my_memcpy.c                  \                
	                $(COREWAR_DIR)/memory/corewar_init.c              \                
	                $(COREWAR_DIR)/cycle/cycle.c                      \                
	                $(COREWAR_DIR)/instructions/instructions_1.c      \                
	                $(COREWAR_DIR)/instructions/instructions_2.c      \                
	                $(COREWAR_DIR)/instructions/instructions_3.c      \                
	                $(COREWAR_DIR)/instructions/instructions_3_2.c    \                
	                $(COREWAR_DIR)/memory/mem_manage.c                \                
	                $(COREWAR_DIR)/memory/reg_manage.c                \                
	                $(COREWAR_DIR)/instructions/instruction.c  

OBJS_TEST	=	$(TEST_SRC:.c=.o)

OBJS_COREWAR	=	$(patsubst $(COREWAR_DIR)/%.c, $(REAL)/%.o, $(SRC_COREWAR))

OBJS_ASM	=	$(patsubst $(ASM_DIR)/%.c, $(REAL)/%.o, $(SRC_ASM))	

OBJS		=	$(OBJS_ASM) $(OBJS_COREWAR) $(OBJS_TEST)

COREWAR		=	corewar

ASM		=	asm

CC		=	gcc

MACRO		=	-D TEST_MACRO

CFLAGS		=	-g -I $(ROOT)/include --coverage $(MACRO) 

LDFLAGS		=	-L $(ROOT)/library -l criterion

NAME		=	test

V		?=	@

all:		$(NAME) exec

$(ASM):		$(ASM_OBJS)
		$(V)printf "$(GREEN)Ct objects into $@ executable$(WHITE)\n"
		$(V)$(CC) -o $@ $(DEF) $(ASM_OBJS) $(CFLAGS) $(LDFLAGS)

$(NAME):	$(OBJS)
		$(V)printf "$(CYAN)Linking test objects and project objects into $@ executable$(WHITE)\n"
		$(V)$(CC) -o $@ $(DEF) $(OBJS) $(CFLAGS) $(LDFLAGS)

$(REAL)/%.o:    $(SRC_DIR)/%.c
		$(V)printf "$(BLUE)Compiling [${ORANGE}$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]$(WHITE)\n"
		$(V)$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

exec:
		$(V)printf "$(GREEN)Executing all test !\n$(WHITE)\n\t"
		$(V)./test
		$(V)printf "\n"

clean:
		$(V)printf "$(ORANGE)Cleaning gcda gcno and objects files$(WHITE)\n"
		$(V)rm -f $(addsuffix .gcno, $(basename $(OBJS)))
		$(V)rm -f $(addsuffix .gcda, $(basename $(OBJS)))
		$(V)rm -f $(OBJS)

fclean:		clean
		$(V)printf "$(ORANGE)Deleting binary $(NAME)$(WHITE)\n"
		$(V)rm -f $(NAME)

re:		fclean
		$(V)make --no-print-directory all

.PHONY:	re  clean  fclean  all  exec

.SILENT: $(OBJS)
