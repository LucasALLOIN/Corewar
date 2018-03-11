##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## root makefile
##

DEB 	?=	0

NAME	=	asm

all:	$(NAME)

$(NAME):
	@make --no-print-directory -C sources/ all

re:
	@make --no-print-directory -C sources/ re

debug:
	@make --no-print-directory -C sources/ re DEB=1

clean:
	@make --no-print-directory -C sources/ clean

fclean:
	@make --no-print-directory -C sources/ fclean

test_run:
	@make --no-print-directory -C bonus/unittest re

test_clear:
	@make --no-print-directory -C bonus/unittest fclean

docker:
	@sudo docker run -it -v `pwd`:/home/epitest -w /home/epitest epitechcontent/epitest-docker /bin/bash

.PHONY:	re	clean	fclean	test_run test_clear all docker
