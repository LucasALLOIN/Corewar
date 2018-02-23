/*
** EPITECH PROJECT, 2017
** sources/error_handlers/file_error.c
** File description:
**
*/

#include <unistd.h>
#include "utils.h"
#include "op.h"

static int check_name(char **lines)
{
	if (match(lines[0], ".comment \"*\"")) {
		err_write("The comment must be just after the name.\n", 0);
		return (84);
		
	} else if (!match(lines[0], ".name \"*\"")) {
		for (int i = 1; lines[i]; i++) {
			if (match(lines[i], ".name \"*\"")) {
				err_write("The name of your program must be the first line.\n", i + 1);
				return (84);
			}
		}
		err_write("No name specified.\n", 20);
		return (84);
	}
	if (my_strlen(lines[0]) >= PROG_NAME_LENGTH + 8) {
		err_write("The program name is too long.\n", 0);
		return (84);
	}
	for (int i = 1; lines[i]; i++) {
		if (match(lines[i], ".name \"*\"")) {
			err_write("The name can only be defined once.\n", 3);
			return (84);
		}
	}
	return (0);
}

static int check_comment(char **lines)
{	
	if (!match(lines[1], ".comment \"*\"")) {
		for (int i = 2; lines[i]; i++) {
			if (match(lines[i], ".comment \"*\"")) {
				err_write("The comment must be just after the name.\n", 2);
				return (84);
			}
		}
		err_write("No comment specified.\n", 2);
		return (84);
	}
	if (my_strlen(lines[0]) >= COMMENT_LENGTH + 11) {
		err_write("The comment is too long.\n", 25);
		return (84);
	}
	for (int i = 2; lines[i]; i++) {
		if (match(lines[i], ".comment \"*\"")) {
			err_write("The comment can only be defined once.\n", 38);
			return (84);
		}
	}
	return (0);
}

static int check_instructions(char **lines)
{
	return (0);
}

int file_error_handler(char const *file)
{
	GARBAGE_ARR char **lines = split_lines(file);

	if (check_name(lines))
		return (84);
	else if (check_comment(lines))
		return (84);
	else if (check_instructions(lines))
		return (84);
	return (0);
}