/*
** EPITECH PROJECT, 2018
** instructions.h
** File description:
** instructions header
*/

#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#define NB_INSTRUCTIONS 0x10
#define REG process->registers

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

static const int cycle_x[16] = {1, 10, 5, 5, 10, 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2};

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
int check_valid(int *args, int one, int two, int th);
int get_next_process_id(core_t *core);
void dup_process(process_t *process, int newpc, int id);

#endif  /* INSTRUCTIONS_H_ */
