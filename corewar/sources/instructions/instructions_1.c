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
	int newpc;
	int newid = get_next_process_id(core);

	newpc = process->pc + \
	(uchar_to_short(core, ADRESS(process->pc + 1)) % IDX_MOD);
	dup_process(process, newpc, newid);
	process->pc += 3;
	return(1);
}

int instruction_lfork(core_t *core, process_t *process, int *args)
{
	int newpc;
	int newid = get_next_process_id(core);

	newpc = process->pc + \
	(uchar_to_short(core, ADRESS(process->pc + 1)));
	dup_process(process, newpc, newid);
        process->pc += 3;
	return(1);
}

int instruction_aff(core_t *core, process_t *process, int *args)
{
	int reg = 0;
	int c;
	int character;

	if (!check_valid(args, T_REG, 0, 0)) {
		process->pc += 1;
		return (0);
	}
	reg = uchar_to_int(core, ADRESS(process->pc + 2));
	c = reg_to_int(process->registers[reg]) % 256;
	character = (char) c;
	if (c > 31 && c < 127)
		my_putchar(character);
	process->pc = process->pc + 6;
        return(1);
}


