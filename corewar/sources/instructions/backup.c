/*
** EPITECH PROJECT, 2017
** backup.c
** File description:
** backup
*/

//st
unsigned int pc = process->pc;
byte_t *memory = core->memory;
byte_t **reg = process->registers;
int index_reg = memory[ADRESS(pc + 2)];

if (!check_valid(args, T_REG, T_IND | T_REG, 0) ||
    index_reg <= 0 || index_reg > 16)
        return (process->carry = 0);
if (args[1] == T_REG) {
        if (memory[ADRESS(pc + 3)] <= 0 || memory[ADRESS(pc + 3)] > 16)
                return (progress->carry = 0);
        int_to_reg(reg_to_int(reg[index_reg - 1]), 
                   reg[memory[ADRESS(pc + 3) - 1]]);
        process->pc += 4;
} else if (args[1] == T_IND) {
        int_to_uchar(core, process, \
        reg_to_int(reg[index_reg - 1]), \
        pc + uchar_to_int(core, memory[ADRESS(pc + 3) - 1]));
}
return (process->carry = 1);

int instruction_error(UNUSED core_t *core, process_t *process, int *args)
{
	my_printf("\e[1;34mGood Job process %s you lost 1 cycle\e[0m\n" \
			, process->parent->header.prog_name);
	process->pc += 1;
	return(1);
}

int instruction_ld(core_t *core, process_t *process, int *args)
{
	unsigned int pc = process->pc;
	byte_t *memory = core->memory;
	byte_t **reg = process->registers;

	if (!check_valid(args, T_DIR | T_IND, T_REG, 0))
		return (process->carry = 0);
	if (args[0] == T_DIR) {
		if (memory[pc + 6] <= 0 || memory[pc + 6] > 16)
			return (process->pc += 7);
		int_to_reg(uchar_to_int(core, pc + 2), reg[memory[pc + 6]]);
    		process->pc += 7;
	} else if (args[0] == T_IND) {
		if (memory[pc + 4] <= 0 || memory[pc + 4] > 16)
			return (process->pc += 5);
		short_to_reg(uchar_to_short(core, pc + \
		uchar_to_short(core ,pc + 2) % IDX_MOD), reg[memory[pc + 4]]);
	    	process->pc += 5;
	}
	return (process->carry = 1);
}

int instruction_lld(core_t *core, process_t *process, int *args)
{
	unsigned int pc = process->pc;
	byte_t *memory = core->memory;
	byte_t **reg = process->registers;

	if (!check_valid(args, T_DIR | T_IND, T_REG, 0))
		return (process->carry = 0);
	if (args[0] == T_DIR) {
		if (memory[pc + 6] <= 0 || memory[pc + 6] > 16)
			return (process->carry);
	    	int_to_reg(uchar_to_int(core, pc + 2), \
		process->registers[memory[pc + 6]]);
	    	process->pc += 7;
	} else if (args[0] == T_IND) {
		if (memory[pc + 4] <= 0 || memory[pc + 4] > 16)
			return (process->carry);
	    	short_to_reg(uchar_to_short(core, pc + \
		uchar_to_short(core ,pc + 2)), reg[memory[pc + 4]]);
	    	process->pc += 5;
	}
	return (process->carry = 1);
}
