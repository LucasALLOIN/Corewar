/*
** EPITECH PROJECT, 2017
** sources/asm.c
** File description:
** Main file for the assembler
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "asm.h"
#include "utils.h"

int assembler(int ac, char **av)
{
	int fd = open("test.s", O_RDONLY);
	int fd2 = open("test.cor", O_CREAT | O_RDWR);
	char *name = get_file(fd);
	char *comment;

	//detect_name(fd, &name);
	//detect_comment(fd, &comment);

	//write(1, name, my_strlen(name));

	//write(1, comment, my_strlen(comment));

	//encode_name("zork", fd);
	//encode_description("description", fd);
	//write(fd, "Hello !", 7);
	write(1, name, my_strlen(name));
	write(fd2, name, my_strlen(name));
	close(fd);
	close(fd2);
	return (0);
}