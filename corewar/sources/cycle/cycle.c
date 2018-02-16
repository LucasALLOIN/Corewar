/*
** EPITECH PROJECT, 2017
** cycle.c
** File description:
** cycle handling
*/

#include <stdlib.h>
#include "corewar.h"
#include "my_printf.h"

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

void val_to_b(byte_t byte)
{
	char val[9];

	val[0] = (byte & 0x80) ? '1' : '0';
	val[1] = (byte & 0x40) ? '1' : '0';
	val[2] = (byte & 0x20) ? '1' : '0';
	val[3] = (byte & 0x10) ? '1' : '0';
	val[4] = (byte & 0x08) ? '1' : '0';
	val[5] = (byte & 0x04) ? '1' : '0';
	val[6] = (byte & 0x02) ? '1' : '0';
	val[7] = (byte & 0x01) ? '1' : '0';
	my_printf("Params in bin: %s\n", val);
}

int exec_process(process_t process, core_t *core, int i)
{
	int *args = NULL;
	int instruction = NULL;

	my_printf("PC: %d\nLoad Adress: %d\nInstuction: %#04x\n", core->process_tab[i].pc, process.load_adress, core->memory[process.pc]);
	val_to_b(process.pc + 1);
	//if (!process.turn_to_exec)
	//	return (process.turn_to_exec--);
	//TODO: get instruction get args
	//args = get_args(core->memory, process);
	//instruction = get_instruction(core->memory, process);
	//INSTRUCTION_ARRAY[core->memory(GET_ADRESS(process.pc))](core, process, args);
	//set_process_counter(process, core, instruction);
	return (0);
}

int cycle(core_t *core)
{
	for (int i = 0; i < core->nb_progs; ++i) {
		exec_process(core->process_tab[i], core, i);
	}/*
	if (!(cycle % cycle_to_die)) {
		check_alive();
		}*/
	core->nbr_cycle++;
}
