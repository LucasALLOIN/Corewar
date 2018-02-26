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


/*
**
** [1]  [2]  [3]
** ---  ---  --- 
** 
** default instruction
** 
*/
int instruction_error(UNUSED core_t *core, process_t *process, UNUSED int *args)
{
	my_printf("\e[1;34mGood Job process %s you lost 1 cycle at PC %d\e[0m\n"
		  , process->parent->header.prog_name, process->pc);
	process->pc += 2;
	return(1);
}

/*
**
** [1]  [2]  [3]
** -ID  R--  --- 
**
** [2] = [1]
**
*/
int instruction_ld(core_t *core, process_t *process, int *args)
{
	unsigned int *pc = &process->pc;
	int last = *pc + 2;
	int value =  get_mem(process, core, args[0], &last);
	int index_reg = get_mem(process, core, args[1], &last);

	if (!check_valid(args, T_DIR | T_IND, T_REG, 0) || 
	    index_reg == -1 || value == -1) {
		*pc += 2;
		return (process->carry = 0);
	}
	int_to_reg(value, REG[index_reg]);
	*pc += last;
	return (process->carry = 1);
}

/*
**
** [1]  [2]  [3]
** RI-  R--  ---  
**
** [2] = [1]
**
*/
int instruction_st(core_t *core, process_t *process, int *args)
{
	unsigned int *pc = &process->pc;
	int last = *pc + 2;
	int value = get_mem(process, core, args[0], &last);
	int index_reg = get_mem(process, core, args[1], &last);

	if (!check_valid(args, T_REG, T_IND | T_REG, 0) ||
	    index_reg == -1 || value == -1) {
		*pc += 2;
		return (process->carry = 0);
	}
	if (args[1] == T_REG)
		int_to_reg(reg_to_int(REG[value]), REG[index_reg]);
	else
		int_to_uchar(core, process, reg_to_int(REG[index_reg]), value);
	return (*pc += last);
}

int instruction_lld(core_t *core, process_t *process, int *args)
{
	unsigned int *pc = &process->pc;
	int last = *pc + 2;
	int index_reg = lget_mem(process, core, args[1], &last);
	int value =  lget_mem(process, core, args[0], &last);

	if (!check_valid(args, T_DIR | T_IND, T_REG, 0) || 
	    index_reg == -1 || value == -1) {
		*pc += 2;
		return (process->carry = 0);
	}
	if (args[1] == T_REG) 
		int_to_reg(reg_to_int(REG[value]), REG[index_reg]);
	else
		int_to_reg(value, REG[index_reg]);
	*pc += last;
	return (process->carry = 1);
}
