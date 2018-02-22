/*
** EPITECH PROJECT, 2017
** sources/encoders/header.c
** File description:
** File encoding headers for assembly
*/

#include <unistd.h>
#include "op.h"
#include "utils.h"

static void encode_name(char const *name, int fd)
{
	union endianner endianner;
	GARBAGE char *memory_zone = my_calloc(PROG_NAME_LENGTH);

	endianner.n = COREWAR_EXEC_MAGIC;
	for (int i = 0; i < 4; i++) {
		memory_zone[i] = endianner.s[4 - (i + 1)];
	}
	for (int i = 0; i < my_strlen(name); i++) {
		memory_zone[i + 4] = name[i];
	}
	write(fd, memory_zone, PROG_NAME_LENGTH);
}

static void encode_description(char const *description, int fd)
{
	GARBAGE char *memory_zone = my_calloc(COMMENT_LENGTH + 16);

	for (int i = 0; i < my_strlen(description); i++) {
		memory_zone[i] = description[i];
	}
	write(fd, memory_zone, COMMENT_LENGTH + 4);
}

void encode_header(header_t *header, int fd) {
	char code = 0;
	union endianner endianner;

	encode_name(header->prog_name, fd);
	endianner.n = header->prog_size;
	for (int i = 8; i; i--) {
		write(fd, &code, 1);
	}
	for (int i = 0; i < 4; i++) {
		write(fd, &(endianner.s[4 - (i + 1)]), 1);
	}
	encode_description(header->comment, fd);
}