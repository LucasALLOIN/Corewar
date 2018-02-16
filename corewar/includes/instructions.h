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

(int) const (*INSTRUCTION_ARRAY) (int *args) = {
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

int instruction_error(int *args);
int instruction_live(int *args);
int instruction_ld(int *args);
int instruction_st(int *args);
int instruction_add(int *args);
int instruction_sub(int *args);
int instruction_and(int *args);
int instruction_or(int *args);
int instruction_xor(int *args);
int instruction_zjmp(int *args);
int instruction_ldi(int *args);
int instruction_sti(int *args);
int instruction_fork(int *args);
int instruction_lld(int *args);
int instruction_lldi(int *args);
int instruction_lfork(int *args);
int instruction_aff(int *args);

#endif  /* INSTRUCTIONS_H_ */
