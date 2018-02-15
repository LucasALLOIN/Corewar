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

int header_parser(int fd, core_t *corewar, int i)
{
	int rd;

	rd = read(fd, &corewar->prog[i].header, sizeof(header_t));
	//corewar->prog[i].header.prog_size = swap_integer(corewar->prog[i].header.prog_size);
	if (rd == -1)
		return (0);
	return (0);
}

int bin_parser(core_t *corewar, int i)
{
	int fd = open(corewar->program_tab[i].file_name, O_RDONLY);

        if (fd == -1 || header_parser(fd, corewar, i))
		return (-1);
	my_printf("%s: %s\n", corewar->prog[i].header.prog_name, corewar->prog[i].header.comment);
	my_printf("Magic: %d, Size: %d\n", corewar->prog[i].header.magic, corewar->prog[i].header.prog_size);
	return (0);
}
