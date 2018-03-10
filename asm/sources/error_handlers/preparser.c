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
		if (line[i] == ',')
			line[i] = ' ';
	}
	temp = clean_str(line);
	free(line);
	return (temp);
}

static void add_lines(char **new_lines, char **lines)
{
	char *temp = 0x0;
	int len_temp = 0;
	int offset = 0;
	int len = 0;

	for (int i = 0; lines[i]; i++) {
		len = my_strlen(lines[i]);
		len_temp = find_next(lines[i], ':');
		if (len_temp != -1 && lines[i][len_temp - 1] != '%' &&
			lines[i][len_temp + 1] == ' ') {
			temp = lines[i] + find_next(lines[i], ':') + 2;
			new_lines[i + offset] = my_calloc(find_next(lines[i], ':') + 1);
			my_memcpy(new_lines[i + offset], lines[i], find_next(lines[i], ':') + 1);
			new_lines[i + offset + 1] = my_calloc(my_strlen(temp) + 1);
			my_memcpy(new_lines[i + offset + 1], temp, my_strlen(temp));
			offset++;
		} else {
			new_lines[i + offset] = my_calloc(len + 2);
			my_memcpy(new_lines[i + offset], lines[i], len);
		}
	}
}

static char **new_line_instructions(char **lines)
{
	int offset = 0;
	int nb_lines = 0;
	char **new_lines = 0x0;

	for (int i = 0; lines[i]; i++, nb_lines++);
	for (int i = find_non_ingored(-1, lines); lines[i];) {
		if (match(lines[i], "*: *") && !match(lines[i], "*%:*") &&
		find_next(lines[i], ' ') != -1)
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
	for (int i = 0; (*lines)[i]; i++) {
		(*lines)[i] = clean_separators((*lines)[i]);
	}
	*lines = sanitize_instructions(*lines);
	*lines = new_line_instructions(*lines);
}