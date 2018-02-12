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

	for (int i = 0; i < REG_NUMBER; ++i)
		core->registers[i].num = i + 1;
	return (core);
}
