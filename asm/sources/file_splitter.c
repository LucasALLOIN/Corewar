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

static char *extract_name(char const *file)
{
	char *result = 0x0;
	int start = 0;
	int end = 0;

	start = find_next(file, '"');
	end = find_next(file + start + 1, '"');
	result = my_calloc(end + 1);
	my_memcpy(result, file + start + 1, end);
	return (result);
}

static char *extract_description(char const *file)
{
	char *result = 0x0;
	int offset = 0;
	int start = 0;
	int end = 0;

	offset = find_next(file, '\n') + 1;
	start = find_next(file + offset, '"');
	end = find_next(file + offset + start + 1, '"');
	result = my_calloc(end + 1);
	my_memcpy(result, file + offset + start + 1, end);
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

char *split(char const *file, header_t *header)
{
	header->prog_name = extract_name(file);
	header->comment = extract_description(file);
	return (extract_code(file));
}