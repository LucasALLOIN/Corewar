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
#include "prog.h"

typedef unsigned char byte;
typedef void* pointer;

/* 
 * Register_t: Register structure.
 *
 * bool if it's the pc.
 * Virtual memory: size defined in op.h.
*/
typedef struct register_s {
	int num;
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
	pointer pc;
	byte memory[MEM_SIZE];
        program_t program_tab[MAX_ARGS_NUMBER];
	int cycle_to_die;
	int nbr_cycle;
	int nb_progs;
	int nb_dump;
} core_t;

core_t *create_core(void);

#endif /* COREWAR_H_ */
