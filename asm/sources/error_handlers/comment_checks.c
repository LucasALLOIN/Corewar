/*
** EPITECH PROJECT, 2017
** sources/error_handlers/comment_checks.c
** File description:
**
*/

#include "utils.h"
#include "op.h"

static int check_after_name(char **lines)
{

	int first_line = find_non_ingored(0, lines);

	first_line = find_non_ingored(first_line, lines);
	for (int i = first_line; lines[i]; i = find_non_ingored(i, lines)) {
		if (match(lines[i], ".comment \"*\"")) {
			err_write("The comment must be just after the name.\n", i + 1);
			return (84);
		}
	}
	return (0);
}

static int check_multiple_def(char **lines)
{
	int first_line = find_non_ingored(0, lines);

	first_line = find_non_ingored(first_line, lines);
	for (int i = find_non_ingored(first_line, lines); lines[i];) {
		if (match(lines[i], ".comment \"*\"")) {
			err_write("The comment can only"
			" be defined once.\n", i + 1);
			return (84);
		}
		i = find_non_ingored(i, lines);
	}
	return (0);
}

static int check_long_comment(char **lines)
{
	int first_line = find_non_ingored(0, lines);

	first_line = find_non_ingored(first_line, lines);
	if (my_strlen(lines[first_line]) >= COMMENT_LENGTH + 11) {
		err_write("The comment is too long.\n", 25);
		return (84);
	}
	return (0);
}

int check_comment(char **lines)
{	
	int first_line = find_non_ingored(-1, lines);
	int code = 0;

	first_line = find_non_ingored(first_line, lines);
	if (!match(lines[first_line], ".comment \"*\"")) {
		if (check_after_name(lines))
			return (84);
		err_write("No comment specified.\n", 0);
		return (84);
	}
	code = code ? code : check_multiple_def(lines);
	code = code ? code : check_long_comment(lines);
	return (code);
}
