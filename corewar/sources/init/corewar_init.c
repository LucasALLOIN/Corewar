/*
** EPITECH PROJECT, 2017
** corewar_init.c
** File description:
** initialisation of the file
*/

#include "unistd.h"
#include "corewar.h"
#include "utils.h"
#include "my_printf.h"

int get_offset(int nbr)
{

}

static int load_memory(process_t process, byte_t memory[])
{
	static int nb = 0;
	char *buffer = my_calloc(process.header.prog_size);
	int offset = 0;

	if (read(process.fd, buffer, process.header.prog_size) == -1)
		return (84);
	//TODO: alloin fait la fonction get offset stp qui \
	retourne la taille en fonction du num du process\n
	offset = get_offset(nb);
	offset = 0;     		//TODO: remove this line
	my_memcpy(memory, buffer + offset, process.header.prog_size);
	my_printf("allo\n");
	dump_virtual_mem(memory);
	nb++;
	return (0);
}

int corewar_init(core_t *core)
{
	for (int i = 0; i < core->nb_progs; ++i)
		load_memory(core->process_tab[i], core->memory);
	return (0);
}
