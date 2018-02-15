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

static int load_memory(process_t process, byte_t memory[])
{
	char buffer[process.header.prog_size];

	if (read(process.fd, buffer, process.header.prog_size) == -1)
		return (84);
	my_memcpy(memory, buffer, process.header.prog_size);
	my_printf("allo\n");
	dump_virtual_mem(memory);
	return (0);
}

//int init_prog(core_t *core, program_t prog)
//{	
//	load_memory(prog, core->memory);
//}

int corewar_init(core_t *core)
{
	for (int i = 0; i < core->nb_progs; ++i)
		load_memory(core->process_tab[i], core->memory);
	return (0);
}
