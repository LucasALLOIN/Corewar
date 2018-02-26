/*
** EPITECH PROJECT, 2017
** instructions_1.c
** File description:
** instructions with 1 parameter
*/

#include "corewar.h"
#include "instructions.h"
#include "op.h"
#include "mem_manage.h"

/*
**
** [1]  [2]  [3]
** RID  R-D  R--
**       
** [3] = memory[pc + [1] % IDX_MOD] + [2]
**       ^^^^^^
**           size = [ ][ ]
*/
int instruction_ldi(core_t *core, process_t *process, int *args)
{
	unsigned int *pc = &process->pc;
	int last = *pc + 2;
	int value_1 = get_mem(process, core, T_IND, &last);
	int value_2 = get_mem(process, core, T_IND, &last);
	int index_reg = get_mem(process, core, args[2], &last);

	if (!check_valid(args, T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG) ||
	    index_reg == -1 || value_1 == -1 || value_2 == -1)
		return (*pc += last);
	if (args[0] == T_REG)
		value_1 = reg_to_int(REG[value_1]);
	if (args[1] == T_REG)
		value_2 = reg_to_int(REG[value_2]);
	int_to_reg(uchar_to_short(core, *pc + value_1 % IDX_MOD) + \
		   value_2, REG[index_reg]);
	*pc += last;
	return(process->carry = 1);
}

/*
** [1]  [2]  [3]
** R    RID  RID  
**
** memory[pc + [2] + [3] % IDX_MOD] = [1];
** ^^^^^^
**     size [ ][ ][ ][ ]
**
*/
int instruction_sti(core_t *core, process_t *process, int *args)
{
	unsigned int *pc = &process->pc;
	int last = *pc + 2; 
	int index_reg = get_mem(process, core, args[0], &last);
	int value_1 = get_mem(process, core, args[1], &last);
	int value_2 = get_mem(process, core, args[2], &last);

	if (!check_valid(args, T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG) ||
	    index_reg == -1 || value_1 == -1 || value_2 == -1)
		return (*pc += last);
	if (args[1] == T_REG)
		value_1 = reg_to_int(REG[value_1]);
	if (args[2] == T_REG)
		value_2 = reg_to_int(REG[value_2]);
	int_to_uchar(core, process, reg_to_int(REG[index_reg]), \
		     ADRESS(*pc + value_1 + value_2) % IDX_MOD);
	*pc += last;
	return(1);
}

/*
** [1]  [2]  [3]
** R    RID  RID  
**
** memory[pc + [2] + [3]] = [1];
** ^^^^^^
**     size [ ][ ][ ][ ]
**
*/
int instruction_lldi(core_t *core, process_t *process, int *args)
{
	unsigned int *pc = &process->pc;
	int last = *pc + 2;
	int value_1 = lget_mem(process, core, T_IND, &last);
	int value_2 = lget_mem(process, core, T_IND, &last);
	int index_reg = lget_mem(process, core, args[2], &last);

	if (!check_valid(args, T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG) ||
	    index_reg == -1 || value_1 == -1 || value_2 == -1)
		return (*pc += last);
	if (args[0] == T_REG)
		value_1 = reg_to_int(REG[value_1]);
	if (args[1] == T_REG)
		value_2 = reg_to_int(REG[value_2]);
	int_to_reg(uchar_to_short(core, *pc + value_1) + value_2, REG[index_reg]);
	*pc += last;
	return(process->carry = 1);
}
