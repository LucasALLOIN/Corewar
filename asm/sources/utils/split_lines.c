/*
** EPITECH PROJECT, 2017
** sources/utils/split_lines.c
** File description:
**
*/

#include "utils.h"

char **split_lines(char const *str)
{
	int n_count = 0;
	char **lines;
	char *temp = str;

	while (find_next(temp, '\n') != -1) {
		temp = temp + find_next(temp, '\n') + 1;
		n_count++;
	}
	temp = str;
	lines = my_calloc(sizeof(char*) * (n_count + 1));
	n_count = 0;
	while (find_next(temp, '\n') != -1) {
		lines[n_count] = my_calloc(find_next(temp, '\n') + 1);
		my_memcpy(lines[n_count], temp, find_next(temp, '\n'));
		temp = temp + find_next(temp, '\n') + 1;
		n_count++;
	}
	return (lines);
}

char **split_spaces(char const *str)
{
	int n_count = 0;
	char **lines;
	char *temp = str;

	while (find_next(temp, ' ') != -1) {
		temp = temp + find_next(temp, ' ') + 1;
		n_count++;
	}
	temp = str;
	lines = my_calloc(sizeof(char*) * (n_count + 1));
	n_count = 0;
	while (find_next(temp, ' ') != -1) {
		lines[n_count] = my_calloc(find_next(temp, ' ') + 1);
		my_memcpy(lines[n_count], temp, find_next(temp, ' '));
		temp = temp + find_next(temp, ' ') + 1;
		n_count++;
	}
	lines[n_count] = my_calloc(my_strlen(temp) + 1);
	my_memcpy(lines[n_count], temp, my_strlen(temp));
	return (lines);
}