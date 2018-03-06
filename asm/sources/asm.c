/*
** EPITECH PROJECT, 2017
** sources/asm.c
** File description:
** Main file for the assembler
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "asm.h"
#include "utils.h"

char *flatten_code(char *code)
{
	GARBAGE_ARR char **lines = split_lines(code);
	char *new_code = 0x0;
	int len = 0;

	for (int i = find_non_ingored(0, lines); lines[i];) {
		new_code = my_strcat(new_code, lines[i]);
		new_code = append(new_code, '\n');
		i = find_non_ingored(i, lines);
	}
	free(code);
	return (new_code);
}

static char *compose_filename(char const *file)
{
	char *new_file = 0x0;
	char *file_temp = 0x0;
	int of = 0;

	while (find_next(file + of, '/') != -1) {
		of = of + find_next(file + of, '/') + 1;
	}
	file_temp = my_calloc(my_strlen(file + of));
	my_memcpy(file_temp, file + of, my_strlen(file + of));
	get_file_name(file_temp);
	if (find_next(file + of, '.') != -1) {
		new_file = my_calloc(find_next(file + of, '.'));
		my_memcpy(new_file, file + of, find_next(file + of, '.'));
	} else {
		new_file = my_calloc(my_strlen(file) + 1);
		my_memcpy(new_file, file + of, my_strlen(file));
	}
	new_file = my_strcat(new_file, ".cor");
	return (new_file);
}

static int assemble(char const *file, char const *filename)
{
	GARBAGE char *new_filename = compose_filename(filename);
	GARBAGE char *program_code = 0x0;
	int skipped_lines = 0;
	header_t *header = my_calloc(sizeof(header_t));
	int fd = open(new_filename, O_CREAT | O_RDWR, S_IRWXU);

	program_code = split(file, header, &skipped_lines);
	program_code = flatten_code(program_code);
	encode_code(program_code, fd, header);
	free(header->prog_name);
	free(header->comment);
	free(header);
	close(fd);
	return (0);
}

int assembler(int ac, char **av)
{
	GARBAGE char *file = 0x0;
	int fd = 0;

	if (ac != 2) {
		write(2, "There should be an argument.\n", 29);
		return (84);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1) {
		write(2, "File couldn't be opened.\n", 25);
		return (84);
	}
	file = get_file(fd);
	compose_filename(av[1]);
	if (error_handler(file))
		return (84);
	assemble(file, av[1]);
	close(fd);
	return (0);
}