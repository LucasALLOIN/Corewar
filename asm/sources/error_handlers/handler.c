/*
** EPITECH PROJECT, 2017
** sources/error_handlers/handler.c
** File description:
** Main handler
*/

#include "utils.h"

static int is_empty(char **lines)
{
	if (!lines) {
		err_write("The file is empty.\n", 0);
		return (84);
	}
	for (int i = 0; lines[i]; i++) {
		if (!ignore_line(lines[i])) {
			return (0);
		}
	}
	err_write("The file is empty.\n", 0);
	return (1);
}

int error_handler(char const *file)
{
	GARBAGE_ARR char **lines = split_lines(file);
	int code = 0;

	code = code ? code : is_empty(lines);
	code = code ? 1 : preparse(&lines);
	code = code ? code : check_name(lines);
	code = code ? code : check_comment(lines);
	code = code ? code : check_labels(lines);
	code = code ? code : check_instructions(lines);
	return (code);
}