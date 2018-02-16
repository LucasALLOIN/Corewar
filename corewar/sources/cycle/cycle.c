/*
** EPITECH PROJECT, 2017
** cycle.c
** File description:
** cycle handling
*/

#include "corewar.h"

int set_process_counter(process_t *process, core_t *core, int instruction)
{
	int temp_pc = process.pc;
	
	if (instruction == 0x01 || instruction == 0x09 ||
	    instruction == 0x0c || instruction == 0x0f || 
	    instruction == 0x10)
		process.pc += 4;
	else if (instruction == 0x02 || instruction == 0x03 ||
		 instruction == 0x0d)
		process.pc += 8;	
	else
		process.pc += 12;
	return (0);
}

int exec_process(process_t process, core_t *core)
{
	int *args = NULL;
	int instruction = NULL;

	if (!process.turn_to_exec)
		return (process.turn_to_exec--);
	//TODO: get instruction get args 
	//args = get_args(core->memory, process);
	//instruction = get_instruction(core->memory, process);
	//INSTRUCTION_ARRAY[core->memory(GET_ADRESS(process.pc))](core, process, args);
	set_process_counter(process, core, instruction);
}

int cycle(core_t *core)
{
/*
 * for (int i = 0; i < core->nb_progs; ++i) {
 * 	exec_process(core->process_tab[i]);
 * }
 * if (!(cycle % cycle_to_die)) {
 * 	check_alive();
 * }
 * core->nbr_cycle++;
 * 
*/
}
