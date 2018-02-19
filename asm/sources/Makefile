##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile of the source file
##


#_-_-_-_-_-_-_-_-_-_-DEFINE_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

PROJECT_ROOT=	../..

ROOT	=	..

SRC_DIR	=	.

CC	=	gcc

NAME	?=	asm

REAL	=	$(ROOT)/release

SRC	=	$(SRC_DIR)/main.c 			\
		$(SRC_DIR)/asm.c 			\
		$(SRC_DIR)/file_splitter.c		\
		$(SRC_DIR)/encoders/header.c		\
		$(SRC_DIR)/encoders/code.c		\
		$(SRC_DIR)/utils/my_calloc.c 		\
		$(SRC_DIR)/utils/my_strlen.c 		\
		$(SRC_DIR)/utils/free_it.c		\
		$(SRC_DIR)/utils/get_next_line.c	\
		$(SRC_DIR)/utils/match.c		\
		$(SRC_DIR)/utils/clean_str.c		\
		$(SRC_DIR)/utils/get_file.c		\
		$(SRC_DIR)/utils/my_strcat.c		\
		$(SRC_DIR)/utils/find_next.c

WARN	=	-W -Wall -Wextra

CFLAGS	=	-I $(ROOT)/includes $(WARN) -g

LDFLAGS	=	-L $(ROOT)/library -l myprintf

LIB	?=	1

TEST	?=	0

DEB	?=      0

G	=	-g

V	?=	@

OBJS	=	$(patsubst $(SRC_DIR)/%.c, $(REAL)/%.o, $(SRC))




#_-_-_-_-_-_-_-_-_-_-_-_CONDITIONS_-_-_-_-_-_-_-_-_-_-_-_-_-_-_



ifeq ($(DEB), 1)
		CFLAGS += $(G)
endif

ifeq ($(TEST), 1)
		CFLAGS	+= $(MACRO)
endif



#-_-_-_-_-_-_-_-_-_-_-_-_-_COLOR_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_


GREEN	=		\e[1;32m

WHITE	=		\e[0m

ORANGE	=		\e[1;33m

RED	=		\e[1;35m

BLUE	=		\e[1;34m


#_-_-_-_-_-_-_-_-_-_-_-_-RULES_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_


all:			$(NAME)

$(NAME):		echo_build $(REAL)/$(NAME)
			$(V)cp $(REAL)/$(NAME) $(ROOT)
			$(V)printf "$(GREEN)Dup $(NAME) into root directory.$(WHITE)\n"


$(REAL)/$(NAME):	buildrepo $(OBJS)
			$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
			$(V)$(CC) -o $(REAL)/$(NAME) $(OBJS) $(LDFLAGS)
			$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(REAL)/%.o:		$(SRC_DIR)/%.c
			$(V)printf "$(BLUE)Compiling [${ORANGE}$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]$(WHITE)\n"
			$(V)$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
			$(V)rm -rf $(OBJS)
			$(V)printf "$(ORANGE)removing object files.$(WHITE)\n"

fclean:	clean
			$(V)rm -f $(REAL)/$(NAME)
			$(V)rm -f $(ROOT)/$(NAME)
			$(V)printf "$(ORANGE)removing binary file.$(WHITE)\n"

buildrepo:
			$(call make-repo)

re:			fclean
			$(V)make --no-print-directory all 

echo_build:		echo_debug
			$(V)printf "$(GREEN)Begin of the build !\n$(ORANGE)Warnings : \n$(WHITE)"

echo_debug:
			$(V)if [ $(DEB) == 1 ]; then\
				printf "$(RED)debug mode initialized.$(WHITE)\n";\
			fi

.PHONY: 		clean fclean debug all re echo_build echo_debug buildrepo



#_-_-_-_-_-_-_-_-_-_-_-FUNCTIONS_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-



define make-repo
			$(V)for dir in $(dir $(OBJS)); \
			do 			  \
				mkdir -p $$dir;	  \
			done
endef
