/*
** EPITECH PROJECT, 2018
** core.c
** File description:
** core
*/

#include "utils.h"
#include "op.h"
#include "corewar.h"

core_t *create_core(void) {
	core_t *core = my_calloc(sizeof(core_t));
	
	for (int i = 0; i < MAX_ARGS_NUMBER; ++i) {
		core->process_tab[i].load_adress = -1;
	}
        return (core);
}
