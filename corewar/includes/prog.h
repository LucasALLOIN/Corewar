/*
** EPITECH PROJECT, 2018
** prog.h
** File description:
** program header struct
*/

#ifndef PROG_H_
#define PROG_H_

#include "prog.h"
#include "corewar.h"

typedef struct prog_s {
	register_t registers[REG_NUMBER];
        unsigned long load_adress;
	char *name;
	int number;
} prog_t;

#endif /* PROG_H_ */
