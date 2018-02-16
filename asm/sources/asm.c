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

int encode_name(char const *name, int fd)
{
	union endianner endianner;
	GARBAGE char *memory_zone = my_calloc(PROG_NAME_LENGTH);

	endianner.n = COREWAR_EXEC_MAGIC;
	for (int i = 0; i < 4; i++) {
		memory_zone[i] = endianner.c[4 - (i + 1)];
	}
	for (int i = 0; i < my_strlen(name); i++) {
		memory_zone[i + 4] = name[i];
	}
	write(fd, memory_zone, PROG_NAME_LENGTH);
	return (1);
}

int encode_description(char const *description, int fd)
{
	GARBAGE char *memory_zone = my_calloc(COMMENT_LENGTH + 16);

	for (int i = 0; i < my_strlen(description); i++) {
		memory_zone[i + 11] = description[i];
	}
	write(fd, memory_zone, COMMENT_LENGTH + 16);
	return (1);
}

int assembler(int ac, char **av)
{
	int fd = open("test.cor", O_CREAT | O_RDWR);

	encode_name("zork", fd);
	encode_description("description", fd);
	write(fd, "Hello !", 7);
	close(fd);
	return (0);
}