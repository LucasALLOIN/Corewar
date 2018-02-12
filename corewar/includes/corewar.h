/*
** EPITECH PROJECT, 2018
** corewar.h
** File description:
** corewar header
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include "args.h"
#include "op.h"

typedef unsigned char byte;

/* 
 * Register_t: Register structure.
 *
 * bool if it's the pc.
 * Virtual memory: size defined in op.h.
*/
typedef struct register_s {
	int num;
	int is_pc;
	byte memory[REG_SIZE];
} register_t;

/* 
 * Core_t: Main corewar structure.
 *
 * Virtual cpu: with virtual register defined in op.h.
 * Virtual memory: size defined in op.h.
*/
typedef struct core_s {
	register_t registers[REG_NUMBER];
	byte memory[MEM_SIZE];
        program_t program_tab[MAX_ARGS_NUMBER];
	int cycle_to_die;
	int nbr_cycle;
	int nb_progs;
} core_t;

#endif /* COREWAR_H_ */
