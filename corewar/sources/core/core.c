/*
** EPITECH PROJECT, 2018
** core.c
** File description:
** core
*/

#include <stdlib.h>
#include "utils.h"
#include "op.h"
#include "corewar.h"
#include "my_printf.h"

core_t *create_core(void)
{
	core_t *core = my_calloc(sizeof(core_t));

	core->nb_live = 0;
	core->cycle_to_die = CYCLE_TO_DIE;
	for (int i = 0; i < MAX_ARGS_NUMBER; ++i) {
		core->program_tab[i].process_l = malloc(sizeof(process_t));
		core->program_tab[i].process_l->load_adress = -1;
		core->program_tab[i].process_l->id = i + 1;
	}
	return (core);
}
