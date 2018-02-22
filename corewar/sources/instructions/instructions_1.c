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
#include "utils.h"

//TODO: fork | lfork | aff
int instruction_live(core_t *core, process_t *process, int *args)
{
	int adress = ADRESS(process->pc + 1);

	for (int i = 0; i < core->nb_progs; i++)
	  if (process->parent->number == uchar_to_int(core, adress)) {
			process->parent->last_live_cycle = core->nbr_cycle;
			my_printf("The player %d(%s) is alive.\n",
		        process->parent->number, process->parent->header.prog_name);
		}
	core->nb_live += 1;
	process->pc += 5;
	return(1);
}

int instruction_zjmp(core_t *core, process_t *process, int *args)
{
	int adress = ADRESS(process->pc + 1);

	if (!process->carry)
		return (0);
	process->pc += (uchar_to_short(core, adress) % IDX_MOD);
	return(1);
}

int instruction_fork(core_t *core, process_t *process, int *args)
{
	process->pc += 3;
	return(1);
}

int instruction_lfork(core_t *core, process_t *process, int *args)
{
	process->pc += 3;
	return(1);
}

int instruction_aff(core_t *core, process_t *process, int *args)
{
	int adress = ADRESS(process->pc + 2);

	//my_putchar(uchar_to_int(&core->memory[adress]) % 256);
	return(1);
}


