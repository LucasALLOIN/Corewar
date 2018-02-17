/*
** EPITECH PROJECT, 2018
** core.c
** File description:
** core
*/

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
		core->process_tab[i].load_adress = -1;
	}
	return (core);
}
