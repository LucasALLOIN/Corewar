/*
** EPITECH PROJECT, 2017
** instructions_1.c
** File description:
** instructions with 1 parameter
*/

#include "corewar.h"
#include "instructions.h"
#include "my_printf.h"
#include "op.h"
#include "mem_manage.h"

//TODO: st | lld

int instruction_error(core_t *core, process_t *process, int *args)
{
	my_printf("\e[1;34mGood Job process %s you lost 1 cycle\e[0m\n" \
			, process->parent->header.prog_name);
	process->pc += 1;
	return(1);
}

int instruction_ld(core_t *core, process_t *process, int *args)
{
	unsigned int pc = process->pc;

	if (!check_valid(args, T_REG | T_DIR | T_IND | T_LAB, T_REG, 0))
		return (process->carry = 0);
	if (args[0] == T_REG) {
 		int_to_reg(reg_to_int(process->registers \
		[core->memory[GET_ADRESS(pc + 2)]]), \ 
		process->registers[core->memory[GET_ADRESS(pc + 3)]]);
	    	process->pc += 4;
	} else if (args[0] == T_DIR) {
	    	int_to_reg(uchar_to_int(core, pc + 2), \ 
		process->registers[core->memory[pc + 6]]);
	    	process->pc += 7;
	} else if (args[0] == T_IND || args[0] == T_LAB) {
	    	short_to_reg(uchar_to_short(core, pc + uchar_to_short(core ,pc \
		+ 2) % IDX_MOD), process->registers[core->memory[pc + 4]]);
	    	process->pc += 5;
	}
	return (process->carry = 1);
}

int instruction_st(core_t *core, process_t *process, int *args)
{
	return(1);
}

int instruction_lld(core_t *core, process_t *process, int *args)
{
	return(1);
}
