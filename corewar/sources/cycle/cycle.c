/*
** EPITECH PROJECT, 2017
** cycle.c
** File description:
** cycle handling
*/

#include <stdlib.h>
#include "corewar.h"
#include "instructions.h"
#include "my_printf.h"
#include "mem_manage.h"

int set_process_counter(process_t *process, core_t *core, int instruction)
{
	int temp_pc = process->pc;

	if (instruction == 0x01 || instruction == 0x09 ||
	    instruction == 0x0c || instruction == 0x0f ||
	    instruction == 0x10)
		process->pc += 4;
	else if (instruction == 0x02 || instruction == 0x03 ||
		 instruction == 0x0d)
		process->pc += 8;
	else
		process->pc += 12;
	return (0);
}

void get_ins_args(byte_t byte, int *args)
{
	char val[8];
	int ret = 0;

	val[0] = (byte & 0x80) ? '1' : '0';
	val[1] = (byte & 0x40) ? '1' : '0';
	val[2] = (byte & 0x20) ? '1' : '0';
	val[3] = (byte & 0x10) ? '1' : '0';
	val[4] = (byte & 0x08) ? '1' : '0';
	val[5] = (byte & 0x04) ? '1' : '0';
	val[6] = (byte & 0x02) ? '1' : '0';
	val[7] = (byte & 0x01) ? '1' : '0';
	for (int i = 0; i < 6; i += 2, ret++) {
		if (val[i] == '0' && val[i + 1] == '1')
			args[ret] = T_REG;
		if (val[i] == '1' && val[i + 1] == '0')
			args[ret] = T_DIR;
		if (val[i] == '1' && val[i + 1] == '1')
			args[ret] = T_IND;
	}
}

void tmp_func(core_t *core, process_t *process, int *args, int instruction)
{
	switch (instruction) {
	case LIVE:
		instruction_live(core, process, args);
		break;
	case LD:
		instruction_ld(core, process, args);
		break;
	case ST:
		instruction_st(core, process, args);
		break;
	case ADD:
		instruction_add(core, process, args);
		break;
	case SUB:
		instruction_sub(core, process, args);
		break;
	case AND:
		instruction_and(core, process, args);
		break;
	case OR:
		instruction_or(core, process, args);
		break;
	case XOR:
		instruction_xor(core, process, args);
		break;
	case ZJMP:
		instruction_zjmp(core, process, args);
		break;
	case LDI:
		instruction_ldi(core, process, args);
		break;
	case STI:
		instruction_sti(core, process, args);
		break;
	case FORK:
		instruction_fork(core, process, args);
		break;
	case LLD:
		instruction_lld(core, process, args);
		break;
	case LLDI:
		instruction_lldi(core, process, args);
		break;
	case LFORK:
		instruction_lfork(core, process, args);
		break;
	case AFF:
		instruction_aff(core, process, args);
		break;
	default:
		instruction_error(core, process, args);
	}
}

int exec_process(process_t *process, core_t *core, int i)
{
	int args[3] = {0, 0, 0};
	int instruction = 0;
	int lol = uchar_to_int(process->registers[0]);

	my_printf("PC: %d\nLoad Adress: %d\nInstuction: %#04x\n", lol, process->load_adress, core->memory[process->pc]);
	get_ins_args(core->memory[GET_ADRESS(process->pc + 1)], args);
	for (int i = 0; i < 3; i++)
		my_printf("Args %d: %d\n", i, args[i]);
	//if (!process.turn_to_exec)
	//	return (process.turn_to_exec--);
	//TODO: get instruction get args
	//args = get_args(core->memory, process);
	instruction = core->memory[GET_ADRESS(process->pc)];
	tmp_func(core, process, args, instruction);
	//(*INSTRUCTION_ARRAY[instruction]) (core, process, args);
	set_process_counter(process, core, instruction);
	return (0);
}

int cycle(core_t *core)
{
	for (int i = 0; i < core->nb_progs; ++i) {
		exec_process(&core->process_tab[i], core, i);
	}
	/*
	if (!(cycle % cycle_to_die)) {
		check_alive();
		}*/
	core->nbr_cycle++;
}
