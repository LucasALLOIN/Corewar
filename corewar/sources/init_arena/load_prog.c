/*
** EPITECH PROJECT, 2017
** load_prog.c
** File description:
** load all the programs into the memory
*/

#include "corewar.h"

int load_all_program(core_t *corewar)
{
	for(int i = 0; i < corewar->nb_progs; ++i) {
		if (corewar->program_tab[i].load_adresse != NULL)
			load_program(i, corewar, load_adresse);
		else
			load_program(i, corewar, -1);
	}
}
