/*
** EPITECH PROJECT, 2017
** sources/error_handlers/handler.c
** File description:
** Main handler
*/

#include "utils.h"

static int is_empty(char **lines)
{
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

	if (is_empty(lines))
		return (84);
	if (check_name(lines) ||
		check_comment(lines) ||
		check_labels(lines) ||
		check_instructions(lines))
		return (84);
	return (0);
}