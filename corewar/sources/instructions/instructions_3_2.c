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
int get_ldi_mem(process_t *process, core_t *core, int type, int *last)
{
	int value = -1;

	if (type == T_REG && core->memory[*last] <= 16) {
		value = core->memory[*last] - 1;
		*last += 1;
	} else if (type == T_DIR) {
		value = uchar_to_short(core, *last);
		*last += 2;
	}
	return (value);
}

int instruction_ldi(core_t *core, process_t *process, int *args)
{
	unsigned int *pc = &process->pc;
	int last = *pc + 2;
	int value_1 = iget_mem(process, core, args[0], &last);
	int value_2 = get_ldi_mem(process, core, args[1], &last);
	int index_reg = get_mem(process, core, args[2], &last);

	if (!check_valid(args, T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG) ||
		index_reg == -1 || value_1 == -1 || value_2 == -1)
		return (*pc = last);
	if (args[0] == T_REG && value_1 <= 16 && value_1 >= 0)
		value_1 = reg_to_int(REG[value_1]);
	if (args[1] == T_REG && value_2 <= 16 && value_2 >= 0)
		value_2 = reg_to_int(REG[value_2]);
	int_to_reg(uchar_to_int(core, *pc + (value_1 + value_2) % IDX_MOD), \
		REG[index_reg]);
	*pc = last;
	return (process->carry = 1);
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
static int get_sti_mem(process_t *process, core_t *core, int type, int *last)
{
	int value = -1;

	if (type == T_REG) {
		value = core->memory[*last] - 1;
		*last += 1;
	} else if (type == T_DIR) {
		value = uchar_to_short(core, *last);
		*last += 2;
	} else if (type == T_IND) {
		value = uchar_to_short(core, *last);
		*last += 2;
	}
	return (value);
}

int instruction_sti(core_t *core, process_t *process, int *args)
{
	unsigned int *pc = &process->pc;
	int last = *pc + 2;
	int index_reg = get_mem(process, core, args[0], &last);
	int value_1 = get_sti_mem(process, core, args[1], &last);
	int value_2 = get_sti_mem(process, core, args[2], &last);

	if (!check_valid(args, T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG) ||
		index_reg == -1 || value_1 == -1 || value_2 == -1)
		return (*pc = last);
	if (args[1] == T_REG)
		value_1 = reg_to_int(REG[value_1]);
	if (args[2] == T_REG)
		value_2 = reg_to_int(REG[value_2]);
	int_to_uchar(core, process, reg_to_int(REG[index_reg]), \
	ADRESS(*pc + (value_1 + value_2) % IDX_MOD));
	*pc = last;
	return (1);
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
	int value_1 = lget_mem(process, core, args[0], &last);
	int value_2 = get_ldi_mem(process, core, args[1], &last);
	int index_reg = liget_mem(process, core, args[2], &last);

	if (!check_valid(args, T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG) ||
	index_reg == -1 || value_1 == -1 || value_2 == -1)
		return (*pc = last);
	if (args[0] == T_REG)
		value_1 = reg_to_int(REG[value_1]);
	if (args[1] == T_REG)
		value_2 = reg_to_int(REG[value_2]);
	int_to_reg(uchar_to_int(core, *pc + (value_1 + value_2)),
		REG[index_reg]);
	*pc = last;
	return (process->carry = 1);
}
