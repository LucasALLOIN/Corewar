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

static char *extract_name(char const *file)
{
	char *result = 0x0;
	int start = 0;
	int end = 0;

	if (!match(file, ".name*")) {
		write(2, "Name should be on the first line.\n", 34);
	} else {
		start = find_next(file, '"');
		end = find_next(file + start + 1, '"');
		result = my_calloc(end + 1);
		my_memcpy(result, file + start + 1, end);
	}
	return (result);
}

static char *extract_description(char const *file)
{
	char *result = 0x0;
	int offset = 0;
	int start = 0;
	int end = 0;

	if (!match(file, ".comment*")) {
		offset = find_next(file, '\n') + 1;
	}
	if (!match(file + offset, ".comment*")) {
		write(2, "Comment should be on the second line.\n", 38);
	} else {
		start = find_next(file + offset, '"');
		end = find_next(file + offset + start + 1, '"');
		result = my_calloc(end + 1);
		my_memcpy(result, file + offset + start + 1, end);
	}
	return (result);
}

static char *extract_code(char const *file)
{
	char *result = 0x0;
	int of = 0;

	while (match(file + of, ".name*") || match(file + of, ".comment*")) {
		of = of + find_next(file + of, '\n') + 1;
	}
	result = my_calloc(my_strlen(file) - of);
	my_memcpy(result, file + of, my_strlen(file) - of);
	return (result);
}

program_t *split(char const *file)
{
	program_t *program = my_calloc(sizeof(program_t));

	program->name = extract_name(file);
	program->description = extract_description(file);
	program->code = extract_code(file);
	return (program);
}

void free_program(program_t *program)
{
	free(program->name);
	free(program->description);
	free(program->code);
}