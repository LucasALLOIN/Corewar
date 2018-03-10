/*
** EPITECH PROJECT, 2017
** sources/file_splitter.c
** File description:
**
*/

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"
#include "utils.h"
#include "op.h"

static char *extract_name(char **lines)
{
	char *name_line = 0x0;
	char *result = 0x0;
	int start = 0;
	int end = 0;

	for (int i = find_non_ingored(-1, lines); lines[i];) {
		if (!name_line && match(lines[i], ".name*\"*\""))
			name_line = lines[i];
		i = find_non_ingored(i, lines);
	}
	start = find_next(name_line, '"');
	end = find_next(name_line + start + 1, '"');
	result = my_calloc(end + 1);
	my_memcpy(result, name_line + start + 1, end);
	return (result);
}

static char *extract_description(char **lines)
{
	char *comment_line = 0x0;
	char *result = 0x0;
	int offset = 0;
	int start = 0;
	int end = 0;

	for (int i = find_non_ingored(0, lines); lines[i];) {
		if (!comment_line && match(lines[i], ".comment*\"*\""))
			comment_line = lines[i];
		i = find_non_ingored(i, lines);
	}
	offset = find_next(comment_line, '\n') + 1;
	start = find_next(comment_line + offset, '"');
	end = find_next(comment_line + offset + start + 1, '"');
	result = my_calloc(end + 1);
	my_memcpy(result, comment_line + offset + start + 1, end);
	return (result);
}

static char *extract_code(char const *file, int *skipped_lines)
{
	char *result = 0x0;
	int of = 0;

	while (match(file + of, ".name*") || match(file + of, ".comment*")) {
		of = of + find_next(file + of, '\n') + 1;
		(*skipped_lines)++;
	}
	result = my_calloc(my_strlen(file) - of);
	my_memcpy(result, file + of, my_strlen(file) - of);
	return (result);
}

char *split(char const *file, header_t *header, int *skipped_lines)
{
	GARBAGE_ARR char **lines = split_lines(file);

	header->prog_name = extract_name(lines);
	header->comment = extract_description(lines);
	return (extract_code(file, skipped_lines));
}
