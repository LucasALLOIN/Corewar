/*
** EPITECH PROJECT, 2017
** includes/asm.h
** File description:
** Assembler header
*/

#ifndef ASM_H_
#define ASM_H_

void free_it(char **pointer);

#define GARBAGE __attribute__((cleanup(free_it)))

union endianner {
	int n;
	char c[4];
};

int assembler(int ac, char **av);

#endif /* ASM_H_ */