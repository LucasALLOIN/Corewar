/*
** EPITECH PROJECT, 2017
** sources/utils/split_lines.c
** File description:
** Split text
*/

#include "utils.h"

char **split_lines(char const *str)
{
	int ncount = 0;
	int of = 0;
	char **lines;

	if (!str)
		return (0x0);
	while (find_next(str + of, '\n') != -1) {
		of = of + find_next(str + of, '\n') + 1;
		ncount++;
	}
	of = 0;
	lines = my_calloc(sizeof(char *) * (ncount + 2));
	ncount = 0;
	while (find_next(str + of, '\n') != -1) {
		lines[ncount] = my_calloc(find_next(str + of, '\n') + 1);
		my_memcpy(lines[ncount], str + of, find_next(str + of, '\n'));
		of = of + find_next(str + of, '\n') + 1;
		ncount++;
	}
	return (lines);
}

char **split_spaces(char const *str)
{
	int n_count = 0;
	char **lines;
	int of = 0;

	while (find_next(str + of, ' ') != -1) {
		of = of + find_next(str + of, ' ') + 1;
		n_count++;
	}
	of = 0;
	lines = my_calloc(sizeof(char *) * (n_count + 2));
	n_count = 0;
	while (find_next(str + of, ' ') != -1) {
		lines[n_count] = my_calloc(find_next(str + of, ' ') + 1);
		my_memcpy(lines[n_count], str + of, find_next(str + of, ' '));
		of = of + find_next(str + of, ' ') + 1;
		n_count++;
	}
	lines[n_count] = my_calloc(my_strlen(str + of) + 1);
	my_memcpy(lines[n_count], str + of, my_strlen(str + of));
	return (lines);
}
