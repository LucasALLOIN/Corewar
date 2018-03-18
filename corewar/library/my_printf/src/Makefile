##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of the project
##

SRC_DIR	=	.

ROOT	=	../../..

NAME	=	libmyprintf.a

LIB	=	$(ROOT)/library/$(NAME)

SRC	=	$(SRC_DIR)/arg_print/arg_print.c	\
		$(SRC_DIR)/arg_print/flags_functions.c	\
		$(SRC_DIR)/my_printf.c			\
		$(SRC_DIR)/parser/parser.c		\
		$(SRC_DIR)/parser/parser2.c		\
		$(SRC_DIR)/print/little_writer.c	\
		$(SRC_DIR)/print/my_strlen.c		\
		$(SRC_DIR)/print/print_base.c		\
		$(SRC_DIR)/print/print_string.c		\
		$(SRC_DIR)/print/print_unsigned.c	\
		$(SRC_DIR)/utils/struct_funct.c		\
		$(SRC_DIR)/utils/utils.c

OBJS	=	$(SRC:.c=.o)

V	?=	@

CC	=	gcc

CFLAGS	=	-I ../include/


#-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


GREEN   =       \e[1;32m

WHITE   =       \e[0m

ORANGE  =       \e[1;33m

RED     =	\e[1;35m

BLUE    =	\e[1;34m

#_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


.PHONY: 	all
all:		$(LIB)

$(LIB):		$(OBJS)
		$(V)printf "$(GREEN)Creating my_printf library.\n$(WHITE)"
		$(V)ar rc $@ $(OBJS)

.PHONY: 	clean fclean re
clean:
		$(V)printf "$(ORANGE)Removing my_printf objects.\n$(WHITE)"
		$(V)rm -f $(OBJS)

fclean: 	clean
		$(V)printf "$(RED)Removing my_printf library.\n$(WHITE)"
		$(V)rm -f $(LIB)

re:		fclean
		$(V)make --no-print-directory all

%.o:		%.c
		$(V)printf "$(BLUE)Compiling [$(ORANGE)$(notdir $<)$(BLUE) -> $(RED) $(notdir $@) $(BLUE)]\n$(WHITE)"
		$(V)$(CC) -o $@  -c $< $(CFLAGS)
