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

(int) const (*INSTRUCTION_ARRAY) (core_t *core, process_t process, int *args) = {
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
