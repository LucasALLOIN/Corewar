/*
** EPITECH PROJECT, 2017
** sources/encoders/label_utils.c
** File description:
** utility for label creation
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "utils.h"

char *clean_separator(char *str)
{
	char *result = 0x0;

	if (str[my_strlen(str) - 1] == SEPARATOR_CHAR) {
		result = my_calloc(my_strlen(str));
		my_memcpy(result, str, my_strlen(str) - 1);
	} else {
		result = my_calloc(my_strlen(str) + 1);
		my_memcpy(result, str, my_strlen(str));
	}
	free(str);
	return (result);
}

int create_label(label_t *label, char **lines)
{
	int max_lines = 0;
	int label_lines = 0;

	label->name = my_calloc(my_strlen(lines[0]));
	my_memcpy(label->name, lines[0], my_strlen(lines[0]) - 1);
	for (int i = 0; lines[i]; i++, max_lines++) {
		if (!label_lines && match(lines[i], "*:") && !match(lines[i], "*%:"))
			label_lines = i;
	}
	label_lines = label_lines ? label_lines : max_lines;
	label->lines = my_calloc(sizeof(char*) * (label_lines + 1));
	for (int i = 1; i < label_lines; i++) {
		label->lines[i - 1] = my_calloc(my_strlen(lines[i]) + 1);
		my_memcpy(label->lines[i - 1], lines[i], my_strlen(lines[i]));
	}
	return (label_lines);
}

int compute_line_size(char const *line)
{
	int size = has_not_coding_byte(line) ? 1 : 2;
	char **params = split_spaces(line);

	printf("%s ", params[0]);
	for (int i = 1; params[i]; i++) {
		params[i] = clean_separator(params[i]);
		printf("%s ", params[i]);
		switch (params[i][0]) {
		case REG_CHAR:
			size += 1;
			break;
		case DIRECT_CHAR:
			size += params[i][1] == LABEL_CHAR ? IND_SIZE : DIR_SIZE;
			break;
		default:
			size += IND_SIZE;
		}
		free(params[i]);
	}
	printf("\n");
	free(params[0]);
	free(params);
	return (size);
}

int compute_label_size(label_t *label)
{
	int size = 0;

	for (int i = 0; label->lines[i]; i++) {
		size += compute_line_size(label->lines[i]);	
	}
	return (size);
}

void free_instructions(ins_t **ins)
{
	for (int i = 0; ins[i]; i++) {
		free(ins[i]);
	}
	free(ins);
}
