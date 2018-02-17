/*
** EPITECH PROJECT, 2017
** instructions_1.c
** File description:
** instructions with 1 parameter
*/

#include "corewar.h"
#include "instructions.h"
#include "my_printf.h"
#include "mem_manage.h"

int instruction_live(core_t *core, process_t *process, int *args)
{
	int adress = GET_ADRESS(process->pc + 1);

	for (int i = 0; i < core->nb_progs; i++)
		if (process->number == uchar_to_int(&core->memory[adress])) {
			//do things
			my_printf("The player %d(%s) is alive.\n",
		        process->number, process->header.prog_name);
		}
	process->pc += 5;
	return(1);
}

int instruction_zjmp(core_t *core, process_t *process, int *args)
{
	
	return(1);
}

int instruction_fork(core_t *core, process_t *process, int *args)
{
	return(1);
}

int instruction_lfork(core_t *core, process_t *process, int *args)
{
	return(1);
}

int instruction_aff(core_t *core, process_t *process, int *args)
{
	return(1);
}


