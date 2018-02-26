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

/*
**
** [1] [2] [3]
**  R   R   R
**
** [3] = [1] + [2]
*/
int instruction_add(core_t *core, process_t *process, UNUSED int *args)
{
	int r1 = core->memory[ADRESS(process->pc + 2)] - 1;
	int r2 = core->memory[ADRESS(process->pc + 3)] - 1;
	int r3 = core->memory[ADRESS(process->pc + 4)] - 1;
	int sum;

	if (!((r1 >= 0 && r1 <= 15) && (r2 >= 0 && r2 <= 15) && \
	(r3 >= 0 && r3 <= 15))) {
		process->carry = 0;
		process->pc += 5;
		return (0);
	}
	sum = reg_to_int(process->registers[r1]) + \
	reg_to_int(process->registers[r2]);
	int_to_reg(sum, process->registers[r3]);
	process->pc += 5;
	process->carry = 1;
	return(1);
}

/*
**
** [1] [2] [3]
**  R   R   R
**
** [3] = [1] - [2]
*/
int instruction_sub(core_t *core, process_t *process, UNUSED int *args)
{
	int r1 = core->memory[ADRESS(process->pc + 2)] - 1;
	int r2 = core->memory[ADRESS(process->pc + 3)] - 1;
	int r3 = core->memory[ADRESS(process->pc + 4)] - 1;
	int sub;

	if (!((r1 >= 0 && r1 <= 15) && (r2 >= 0 && r2 <= 15) && \
	      (r3 >= 0 && r3 <= 15))) {
		process->carry = 0;
		process->pc += 5;
		return (0);
	}
	sub = reg_to_int(process->registers[r1]) - \
	reg_to_int(process->registers[r2]);
	int_to_reg(sub, process->registers[r3]);
	process->pc += 5;
	process->carry = 1;
	return(1);
}

/*
**
** [1] [2] [3]
** DIR DIR  R
**
** [3] = [1] & [2]
*/
int instruction_and(core_t *core, process_t *process, int *args)
{
	int last = process->pc + 2;
	int value_1 = get_mem(process, core, args[0], &last);
	int value_2 = get_mem(process, core, args[1], &last);
	int value_3 = get_mem(process, core, args[2], &last);
	int and = 0;

	if (check_valid(
	    args, T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG), 
	    value_1 == -1 || value_2 == -1 || value_3 == -1) {
		process->carry = 0;
		return (process->pc += 2);
	}
	and = reg_to_int(REG[value_1]) & reg_to_int(REG[value_2]);
	int_to_reg(and, REG[value_3]);
	process->pc += last;
	process->carry = 1;
	return(1);
}

/*
**
** [1] [2] [3]
** DIR DIR  R
**
** [3] = [1] | [2]
*/
int instruction_or(core_t *core, process_t *process, int *args)
{
	int last = process->pc + 2;
	int value_1 = get_mem(process, core, args[0], &last);
	int value_2 = get_mem(process, core, args[1], &last);
	int value_3 = get_mem(process, core, args[2], &last);
	int or = 0;

	if (check_valid(
	    args, T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG), 
	    value_1 == -1 || value_2 == -1 || value_3 == -1) {
		process->carry = 0;
		return (process->pc += last);
	}
	or = reg_to_int(REG[value_1]) | reg_to_int(REG[value_2]);
	int_to_reg(or, REG[value_3]);
	process->pc += last;
	process->carry = 1;
	return(1);
}

/*
**
** [1] [2] [3]
** DIR DIR  R
**
** [3] = [1] ^ [2]
*/
int instruction_xor(core_t *core, process_t *process, int *args)
{
	int last = process->pc + 2;
	int value_1 = get_mem(process, core, args[0], &last);
	int value_2 = get_mem(process, core, args[1], &last);
	int value_3 = get_mem(process, core, args[2], &last);
	int xor = 0;

	if (check_valid(
	    args, T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG), 
	    value_1 == -1 || value_2 == -1 || value_3 == -1) {
		process->carry = 0;
		return (process->pc += last);
	}
	xor = reg_to_int(REG[value_1]) ^ reg_to_int(REG[value_2]);
	int_to_reg(xor, REG[value_3]);
	process->pc += last;
	process->carry = 1;
	return(1);
}

