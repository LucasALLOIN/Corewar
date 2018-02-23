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
		write(2, "The comment must be just after the name.\n", 42);
		return (84);
		
	} else if (!match(lines[0], ".name \"*\"")) {
		for (int i = 1; lines[i]; i++) {
			if (match(lines[i], ".name \"*\"")) {
				write(2, "The name of your program must be the first line.\n", 49);
				return (84);
			}
		}
		write(2, "No name specified.\n", 19);
		return (84);
	}
	if (my_strlen(lines[0]) >= PROG_NAME_LENGTH + 8) {
		write(2, "The program name is too long.\n", 30);
		return (84);
	}
	for (int i = 1; lines[i]; i++) {
		if (match(lines[i], ".name \"*\"")) {
			write(2, "The name can only be defined once.\n", 35);
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
				write(2, "The comment must be just after the name.\n", 42);
				return (84);
			}
		}
		write(2, "No comment specified.\n", 22);
		return (84);
	}
	if (my_strlen(lines[0]) >= COMMENT_LENGTH + 11) {
		write(2, "The comment is too long.\n", 25);
		return (84);
	}
	for (int i = 2; lines[i]; i++) {
		if (match(lines[i], ".comment \"*\"")) {
			write(2, "The comment can only be defined once.\n", 38);
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