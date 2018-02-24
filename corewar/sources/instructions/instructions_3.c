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

//TODO: and | or | xor

int instruction_add(core_t *core, process_t *process, int *args)
{
	int r1 = core->memory[ADRESS(process->pc + 2)] - 1;
	int r2 = core->memory[ADRESS(process->pc + 3)] - 1;
	int r3 = core->memory[ADRESS(process->pc + 4)] - 1;
	int sum;

	(void) args;
	sum = reg_to_int(process->registers[r1]) + \
	reg_to_int(process->registers[r2]);
	int_to_reg(sum, process->registers[r3]);
	process->pc += 5;
	return(1);
}

int instruction_sub(core_t *core, process_t *process, int *args)
{
	int r1 = core->memory[ADRESS(process->pc + 2)] - 1;
	int r2 = core->memory[ADRESS(process->pc + 3)] - 1;
	int r3 = core->memory[ADRESS(process->pc + 4)] - 1;
	int sub;

	(void) args;
	sub = reg_to_int(process->registers[r1]) - \
	reg_to_int(process->registers[r2]);
	int_to_reg(sub, process->registers[r3]);
	process->pc += 5;
	return(1);
}

int instruction_and(core_t *core, process_t *process, int *args)
{
	int last = process->pc + 2;
	int value_1 = get_mem(process, core, args[0], &last);
	int value_2 = get_mem(process, core, args[2], &last);
	int value_3 = get_mem(process, core, args[3], &last);

	if (check_valid(args, T_REG | T_DIR | T_IND,
			T_REG | T_IND | T_DIR, T_REG));
	
	return(1);
}

int instruction_or(core_t *core, process_t *process, int *args)
{
		process->pc += args[0] + args[1] + args[2] + 1;
	return(1);
}

int instruction_xor(core_t *core, process_t *process, int *args)
{
	process->pc += args[0] + args[1] + args[2] + 2;
	return(1);
}

