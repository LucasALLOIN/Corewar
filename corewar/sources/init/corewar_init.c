/*
** EPITECH PROJECT, 2017
** corewar_init.c
** File description:
** initialisation of the file
*/

#include "corewar.h"

int load_memory(int fd, byte memory[])
{

}

int init_prog(core_t *core, program_t *prog)
{	
	core->memory	
}

int corewar_init(core_t *core)
{
	for (int i = 0; i < core->nb_progs; ++i) {
			init_prog(core, core->program_tab[i]);
	}
}
