/*
** EPITECH PROJECT, 2017
** sources/encoders/header.c
** File description:
** File encoding headers for assembly
*/

#include <unistd.h>
#include "op.h"
#include "utils.h"

int detect_name(int fd, char **name)
{
	char *temp = get_next_line(fd);

	while (temp) {
		if (temp[0] == '#') {
			temp = get_next_line(fd);
		} else if (match(".name *", temp)) {
			*name = temp;
			return (0);
		} else {
			return (1);
		}
	}
	return (1);
}

int detect_comment(int fd, char **desc)
{
	char *temp = get_next_line(fd);

	while (temp) {
		if (temp[0] == '#') {
			temp = get_next_line(fd);
		} else if (match(".comment *", temp)) {
			*desc = temp;
			return (0);
		} else {
			return (1);
		}
	}
	return (1);
}

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