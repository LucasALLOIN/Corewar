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

int bitwise_value(int val)
{
	int res;

	res = (val >> 24) & 0xFF;
	res |= (val << 8) & 0xFF0000;
	res |= (val >> 8) & 0xFF00;
	res |= (val << 24) & 0xFF000000;
	return (res);
}

int header_parser(int fd, core_t *corewar, int i)
{
	int rd;

	rd = read(fd, &corewar->program_tab[i].header, sizeof(header_t));
#ifdef DEBUG_MODE
	my_printf("Magic before bitwise: %d\n", \
	corewar->program_tab[i].header.magic);
	my_printf("ProgSize before bitwise: %d\n\n", \
	corewar->program_tab[i].header.prog_size);
#endif
	corewar->program_tab[i].header.prog_size = \
	bitwise_value(corewar->program_tab[i].header.prog_size);
	corewar->program_tab[i].header.magic = \
	bitwise_value(corewar->program_tab[i].header.magic);
	if (rd == -1)
		return (0);
	return (0);
}

int bin_parser(core_t *corewar, int i)
{
	int fd = open(corewar->program_tab[i].file_name, O_RDONLY);

	if (fd == -1 || header_parser(fd, corewar, i)) {
		return (-1);
	}
	corewar->program_tab[i].fd = fd;
	return (0);
}
