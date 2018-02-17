/*
** EPITECH PROJECT, 2017
** instructions_1.c
** File description:
** instructions with 1 parameter
*/

#include "corewar.h"
#include "instructions.h"
#include "my_printf.h"

int instruction_error(core_t *core, process_t *process, int *args)
{
	my_printf("\e[1;34mGood Job process %s you lost 1 cycle\e[0m\n" \
			, process->header.prog_name);
	return(1);
}

int instruction_ld(core_t *core, process_t *process, int *args)
{
	return(1);
}

int instruction_st(core_t *core, process_t *process, int *args)
{
	return(1);
}

int instruction_lld(core_t *core, process_t *process, int *args)
{
	return(1);
}

