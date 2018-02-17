/*
** EPITECH PROJECT, 2018
** instructions.h
** File description:
** instructions header
*/

#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#define NB_INSTRUCTIONS 0x10

#include "corewar.h"

int instruction_error(core_t *core, process_t *process, int *args);
int instruction_live(core_t *core, process_t *process, int *args);
int instruction_ld(core_t *core, process_t *process, int *args);
int instruction_st(core_t *core, process_t *process, int *args);
int instruction_add(core_t *core, process_t *process, int *args);
int instruction_sub(core_t *core, process_t *process, int *args);
int instruction_and(core_t *core, process_t *process, int *args);
int instruction_or(core_t *core, process_t *process, int *args);
int instruction_xor(core_t *core, process_t *process, int *args);
int instruction_zjmp(core_t *core, process_t *process, int *args);
int instruction_ldi(core_t *core, process_t *process, int *args);
int instruction_sti(core_t *core, process_t *process, int *args);
int instruction_fork(core_t *core, process_t *process, int *args);
int instruction_lld(core_t *core, process_t *process, int *args);
int instruction_lldi(core_t *core, process_t *process, int *args);
int instruction_lfork(core_t *core, process_t *process, int *args);
int instruction_aff(core_t *core, process_t *process, int *args);

//TODO: fill the array of cycle number
const int cycle[16] = { 0 };

static int (* const INSTRUCTION_ARRAY[17]) (core_t *, process_t *, int *) = {
	&instruction_error,
	&instruction_live,
	&instruction_ld,
	&instruction_st,
	&instruction_add,
	&instruction_sub,
	&instruction_and,
	&instruction_or,
	&instruction_xor,
	&instruction_zjmp,
	&instruction_ldi,
	&instruction_sti,
	&instruction_fork,
	&instruction_lld,
	&instruction_lldi,
	&instruction_lfork,
	&instruction_aff
};

int get_wating_cycle(int instruction);

#endif  /* INSTRUCTIONS_H_ */
