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

int exec_process(process_t *process, core_t *core, int i)
{
	int args[3] = {0, 0, 0};
	int inst = 0;
	int lol = uchar_to_int(&core->memory[GET_ADRESS(process->pc + 1)]);

	my_printf("PC: %d\nLoad Adress: %d\nInstuction: %#04x\n", process->pc, core->cycle_to_die, core->memory[process->pc]);
	get_ins_args(core->memory[GET_ADRESS(process->pc + 1)], args);
	for (int i = 0; i < 3; i++)
		my_printf("Args %d: %d\n", i, args[i]);
	//if (!process.turn_to_exec)
	//	return (process.turn_to_exec--);
	//TODO: get instruction get args
	//args = get_args(core->memory, process);
	inst = core->memory[GET_ADRESS(process->pc)];
	INSTRUCTION_ARRAY[(inst <= 0x0f) ? inst : 0](core, process, args);
	//set_process_counter(process, core, inst);
	return (0);
}

void check_death(process_t *process)
{
	if (process->last_live_cycle == -1) {
		process->is_alive = 0;
	} else
		process->last_live_cycle = -1;
}

int cycle(core_t *core)
{
	for (int i = 0; i < core->nb_progs; ++i) {
		if (core->process_tab[i].is_alive)
			exec_process(&core->process_tab[i], core, i);
	}
	if (core->nb_live >= NBR_LIVE) {
		core->nb_live == 0;
		core->cycle_to_die -= CYCLE_DELTA;
	}
	if (core->nbr_cycle == core->cycle_to_die) {
		for (int i = 0; i < core->nb_progs; i++)
			check_death(&core->process_tab[i]);
		core->nbr_cycle = 0;
	}
	/*
	if (!(cycle % cycle_to_die)) {
		check_alive();
		}*/
	core->nbr_cycle++;
}
