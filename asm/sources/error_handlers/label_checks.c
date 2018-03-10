/*
** EPITECH PROJECT, 2017
** sources/error_handlers/label_checks.c
** File description:
**
*/

#include <stdlib.h>
#include "utils.h"
#include "op.h"

static int check_validity(char const *line, int nb)
{
	int code = 0;
	int found = 1;

	for (int i = 0; line[i]; i++) {
		for (int j = 0; LABEL_CHARS[j]; j++)
			found = found ? !(LABEL_CHARS[j] == line[i]) : found;
		if (found && line[i] != LABEL_CHAR) {
			err_write("Invalid label name.\n", nb);
			return (1);
		}
		found = 1;
	}
	return (code);
}

static int is_in(char const *line, char **labels, int nb)
{
	if (!labels)
		return (0);
	for (int i = 0; labels[i]; i++) {
		if (my_memcmp(line, labels[i])) {
			err_write("Multiple definition"
			" of the same label.\n", nb);
			return (1);
		}
	}
	return (0);
}

static char **put_in(char const *line, char **labels)
{
	int tab_len = 0;
	char **new_tab = 0x0;

	if (labels) {
		for (int i = 0; labels && labels[i]; i++)
			tab_len++;	
		new_tab = my_calloc(sizeof(char*) * ((tab_len) + 2));
		for (int i = 0; labels && labels[i]; i++) {
			new_tab[i] = my_calloc(my_strlen(labels[i]) + 1);
			my_memcpy(new_tab[i], labels[i], my_strlen(labels[i]));
		}
	} else {
		new_tab = my_calloc(sizeof(char*) * (tab_len + 2));
	}
	new_tab[tab_len] = my_calloc(my_strlen(line) + 1);
	my_memcpy(new_tab[tab_len], line, my_strlen(line));
	if (labels)
		free_array(&labels);
	return (new_tab);
}

static int not_contains_label(char const *line, char **labels, int n)
{
	GARBAGE char *temp = 0x0;
	int start = 0;
	int end = 0;
	
	if (!match(line, "*%:*"))
		return (0);
	while (!start || line[start - 1] != '%')
		start = find_next(line, ':');
	end = find_next(line + start, ' ');
	end = end != -1 ? end - 1 : my_strlen(line + start + 1);
	temp = my_calloc(end + 1);
	my_memcpy(temp, line + start + 1, end);
	temp[my_strlen(temp)] = ':';
	for (int i = 0; labels[i]; i++) {
		if (my_memcmp(labels[i], temp))
			return (not_contains_label(line + end, labels, n));
	}
	err_write("Undefined label.\n", n);
	return (1);
}

int check_labels(char **lines)
{
	GARBAGE_ARR char **labels = 0x0;
	int code = 0;

	for (int i = find_non_ingored(0, lines); lines[i];) {
		if (match(lines[i], "*:") && !match(lines[i], "*%:")) {
			code = code ? code : check_validity(lines[i], i + 1);
			code = code ? code : is_in(lines[i], labels, i + 1);
			labels = put_in(lines[i], labels);
		}
		if (code)
			return (84);
		i = find_non_ingored(i, lines);
	}
	for (int i = find_non_ingored(0, lines); lines[i];) {
		if (not_contains_label(lines[i], labels, i + 1))
			return (84);
		i = find_non_ingored(i, lines);
	}
	return (0);
}