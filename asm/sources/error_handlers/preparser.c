/*
** EPITECH PROJECT, 2017
** sources/error_handlers/preparser.c
** File description:
** preparer.c
*/

#include <stdlib.h>
#include "utils.h"

static char *clean_separators(char *line)
{
	char *temp = 0x0;

	for (int i = 0; line[i]; i++) {
		if (line[i] == 44)
			line[i] = ' ';
	}
	temp = clean_str(line);
	free(line);
	return (temp);
}

static void add_lines(char **new, char **lns)
{
	char *tmp = 0x0;
	int len_temp = 0;
	int off = 0;
	int len = 0;

	for (int i = 0; lns[i]; i++) {
		len = my_strlen(lns[i]);
		len_temp = find_next(lns[i], ':');
		if (len_temp != -1 && lns[i][len_temp - 1] != '%' &&
			lns[i][len_temp + 1] == ' ') {
			tmp = lns[i] + find_next(lns[i], ':') + 2;
			new[i + off] = my_calloc(len_temp + 2);
			my_memcpy(new[i + off], lns[i], len_temp + 1);
			new[i + off + 1] = my_calloc(my_strlen(tmp) + 1);
			my_memcpy(new[i + off + 1], tmp, my_strlen(tmp));
			off++;
		} else {
			new[i + off] = my_calloc(len + 2);
			my_memcpy(new[i + off], lns[i], len);
		}
	}
}

static char **new_line_instructions(char **lines)
{
	int offset = 0;
	int nb_lines = 0;
	char **new_lines = 0x0;
	int first_space = 0;

	for (int i = 0; lines[i]; i++, nb_lines++);
	for (int i = find_non_ingored(-1, lines); lines[i];) {
		first_space = find_next(lines[i], ' ');
		if (first_space != -1 && lines[i][first_space - 1] == ':')
			offset++;
		i = find_non_ingored(i, lines);
	}
	new_lines = my_calloc(sizeof(char *) * (nb_lines + offset + 2));
	add_lines(new_lines, lines);
	return (new_lines);
}

static char **sanitize_instructions(char **lines)
{
	int index = find_non_ingored(-1, lines);
	GARBAGE_ARR char **params = 0x0;
	char **new_lines = 0x0;
	int nb_lines = 0;

	for (int i = 0; lines[i]; i++, nb_lines++);
	if (match(lines[index], ".name *")) {
		index = find_non_ingored(index, lines);
		index = find_non_ingored(index, lines);
	}
	params = split_spaces(lines[index]);
	if (!params[1] && match(params[0], "*:"))
		return (lines);
	new_lines = my_calloc(sizeof(char *) * (nb_lines + 2));
	for (int i = 0; i < index; i++)
		new_lines[i] = lines[i];
	new_lines[index] = my_calloc(sizeof(char) * 10);
	my_memcpy(new_lines[index], "________:", 9);
	for (int i = index; lines[i]; i++)
		new_lines[i + 1] = lines[i];
	return (new_lines);
}

void preparse(char ***lines)
{
	int index = -1;

	if (!*lines)
		return;
	index = find_non_ingored(index, *lines);
	for (int i = 0; (*lines)[i]; i++) {
		(*lines)[i] = clean_separators((*lines)[i]);
	}
	if (match((*lines)[index], ".name *")) {
		index = index == -1 ? -1 : find_non_ingored(index, *lines);
		index = index == -1 ? -1 : find_non_ingored(index, *lines);
	}
	if (!(*lines)[index])
		return;
	*lines = sanitize_instructions(*lines);
	*lines = new_line_instructions(*lines);
}