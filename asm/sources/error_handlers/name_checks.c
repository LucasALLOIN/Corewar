/*
** EPITECH PROJECT, 2017
** sources/error_handlers/file_error.c
** File description:
**
*/

#include <unistd.h>
#include "utils.h"
#include "op.h"

static int check_first_line(char **lines)
{
	int first_line = find_non_ingored(0, lines);

	for (int i = first_line; lines[i]; i = find_non_ingored(i, lines)) {
		if (match(lines[i], ".name \"*\"")) {
			err_write("The name of your"
			" program must be the first line.\n", i + 1);
			return (84);
		}
	}
	return (0);
}

static int check_multiple_def(char **lines)
{
	int first_line = find_non_ingored(0, lines);

	for (int i = find_non_ingored(first_line, lines); lines[i];) {
		if (match(lines[i], ".name \"*\"")) {
			err_write("The name can only"
			" be defined once.\n", i + 1);
			return (84);
		}
		i = find_non_ingored(i, lines);
	}
	return (0);
}

static int check_long_name(char **lines)
{
	int first_line = find_non_ingored(0, lines);

	if (my_strlen(lines[first_line]) >= PROG_NAME_LENGTH + 8) {
		err_write("The program name is too long.\n", first_line);
		return (84);
	}
	return (0);
}

int check_name(char **lines)
{
	int first_line = find_non_ingored(0, lines);
	int code = 0;

	if (match(lines[first_line], ".comment \"*\"")) {
		err_write("The comment must be"
		" just after the name.\n", first_line + 1);
		return (84);
	} else if (!match(lines[first_line], ".name \"*\"")) {
		if (check_first_line(lines))
			return (84);
		err_write("No name specified.\n", 0);
		return (84);
	}
	code = code ? code : check_multiple_def(lines);
	code = code ? code : check_long_name(lines);
	return (code);
}
