/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function of the corewar
*/


#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "utils.h"
#include "my_printf.h"
#include "corewar.h"

int char_to_int(unsigned char *c)
{
	//TODO: Make char to int that work
	return ((c[0] + c[1] + c[2] + c[3]));
}

void get_magic(core_t *corewar, int i, int fd)
{
	unsigned char buf[4];

	read(fd, buf, 4);
	corewar->prog[i].header.magic = char_to_int(buf);
}

void get_name(core_t *corewar, int i, int fd)
{
	char buf[PROG_NAME_LENGTH + 1];
	int z = 0;

	read(fd, buf, PROG_NAME_LENGTH + 4);
	for (int x = 0; x < PROG_NAME_LENGTH; x++)
		if (buf[x] != 0) {
			corewar->prog[i].header.prog_name[z] = buf[x];
			z++;
		}
}

void get_file_size(core_t *corewar, int i, int fd)
{
        unsigned char buf[4];

	read(fd, buf, 4);
        corewar->prog[i].header.prog_size = char_to_int(buf);
}

void get_comment(core_t *corewar, int i, int fd)
{
	char buf[COMMENT_LENGTH + 1];
	int z = 0;

	read(fd, buf, COMMENT_LENGTH + 4);
	for (int x = 0; x < COMMENT_LENGTH; x++)
		if (buf[x] != 0) {
			corewar->prog[i].header.comment[z] = buf[x];
			z++;
		}
}

int bin_parser(core_t *corewar, int i)
{
	int fd = open(corewar->program_tab[i].file_name, O_RDONLY);

        if (fd == -1)
		return (-1);
	get_magic(corewar, i, fd);
	get_name(corewar, i, fd);
	get_file_size(corewar, i, fd);
	get_comment(corewar, i, fd);
        my_printf("%s: %s\n", corewar->prog[i].header.prog_name, corewar->prog[i].header.comment);
	my_printf("Magic: %d, Size: %d\n", corewar->prog[i].header.magic, corewar->prog[i].header.prog_size);
	return (0);
}
