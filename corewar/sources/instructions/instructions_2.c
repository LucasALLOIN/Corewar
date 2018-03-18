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
int instruction_error(UNUSED core_t *core, process_t *proce, UNUSED int *arg)
{
	proce->pc += 1;
	return (1);
}

/*
**
** [1]  [2]  [3]
** -ID  R--  ---
**
** [2] = memory[ [1] % IDX_MOD ]
**       ^^^^^^
**       size[ ][ ][ ][ ]
*/
int instruction_ld(core_t *core, process_t *process, int *args)
{
	unsigned int *pc = &process->pc;
	int last = *pc + 2;
	int value =  get_mem(process, core, args[0], &last);
	int index_reg = get_mem(process, core, args[1], &last);

	if (!check_valid(args, T_DIR | T_IND, T_REG, 0) ||
		index_reg == -1 || value == -1) {
		*pc = last;
		return (process->carry = 0);
	}
	int_to_reg(value, REG[index_reg]);
	*pc = last;
	return (process->carry = !value);
}

/*
**
** [1]  [2]  [3]
** RI-  R--  ---
**
** [2] = [1]
**
*/
int get_st_mem(UNUSED process_t *process, core_t *core, int type, int *last)
{
	int value = -1;

	if (type == T_REG) {
		value = core->memory[*last];
		*last += 1;
		return ((value >= 0 && value <= 16) ? value : 0);
	} else {
		value = uchar_to_short(core, *last);
		*last += 2;
		return (value);
	}
	return (value);
}

int instruction_st(core_t *core, process_t *process, int *args)
{
	unsigned int *pc = &process->pc;
	int last = *pc + 2;
	int index_reg = get_mem(process, core, args[0], &last);
	int value = get_st_mem(process, core, args[1], &last);

	if (!check_valid(args, T_REG, T_IND | T_REG, 0) ||
		index_reg == -1 || value == -1) {
		*pc = last;
		return (process->carry = 0);
	}
	if (args[1] == T_REG)
		int_to_reg(reg_to_int(REG[value]), REG[index_reg]);
	else
		int_to_uchar(core, process, reg_to_int(REG[index_reg]), \
				*pc + value % IDX_MOD);
	return (*pc = last);
}

/*
**
** [1]  [2]  [3]
** -ID  R--  ---
**
** [2] = [1]
**
*/
int instruction_lld(core_t *core, process_t *process, int *args)
{
	unsigned int *pc = &process->pc;
	int last = *pc + 2;
	int index_reg = lget_mem(process, core, args[1], &last);
	int value =  lget_mem(process, core, args[0], &last);

	if (!check_valid(args, T_DIR | T_IND, T_REG, 0) ||
		index_reg == -1 || value == -1) {
		*pc = last;
		return (process->carry = 0);
	}
	int_to_reg(value, REG[index_reg]);
	*pc = last;
	return (process->carry = !value);
}
