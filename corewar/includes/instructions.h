/*
** EPITECH PROJECT, 2018
** instructions.h
** File description:
** instructions header
*/

#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#define NB_INSTRUCTIONS 0x10

enum instruction {
	ZERO,
	LIVE,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF
};

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

/*
int  (*INSTRUCTION_ARRAY[17]) (core_t *core, process_t process, int *args) = {
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
*/
#endif  /* INSTRUCTIONS_H_ */
