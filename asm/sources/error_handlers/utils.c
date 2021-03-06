/*
** EPITECH PROJECT, 2017
** sources/error_handlers/utils.c
** File description:
** utils
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "utils.h"

void putnbr_err(int n)
{
	char temp = 0;
	int d;

	if (n < 0)
		return;
	if (n >= 10) {
		d = (n % 10);
		n = (n - d) / 10;
		putnbr_err(n);
		temp = d + 48;
		write(2, &temp, 1);
	} else {
		temp = (n % 10) + 48;
		write(2, &temp, 1);
	}
}

int find_non_ingored(int index, char **lines)
{
	int max_line = 0;

	for (int i = 0; lines[i]; i++, max_line++);
	for (int i = index + 1; lines[i]; i++) {
		if (!ignore_line(lines[i]))
			return (i);
	}
	return (max_line);
}

int ignore_line(char const *line)
{
	if (line[0] == COMMENT_CHAR)
		return (1);
	if (my_strlen(line) <= 1)
		return (1);
	return (0);
}

char *get_file_name(char *str)
{
	static char *database = 0x0;

	if (str) {
		database = str;
	} else if (str == (char *) 1) {
		free(database);
	} else {
		return (database);
	}
	return (0x0);
}

void err_write(char const *error, int line_n)
{
	write(2, "\033[1m", 4);
	write(2, "asm, ", 5);
	write(2, get_file_name(0x0), my_strlen(get_file_name(0x0)));
	write(2, ", line ", line_n ? 7 : 0);
	putnbr_err(line_n ? line_n : -1);
	write(2, ": \033[1;36m", 9);
	write(2, error, my_strlen(error));
	write(2, "\033[0m", 4);
	get_file_name((char *) 1);
}
