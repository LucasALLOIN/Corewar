/*
** EPITECH PROJECT, 2017
** cycle.c
** File description:
** cycle handling
*/

#include "corewar.h"

int set_process_counter(process_t *process, core_t *core)
{
	int temp_pc = process.pc;
	
	while (core->memory[GET_ADRESS(++temp_pc)] > NB_INSTRUCTIONS);
	process.pc = temp_pc;
	return (0);
}

int exec_process(process_t process, core_t *core)
{
	if (!process.turn_to_exec) {
		process.turn_to_exec--;
		return (1);
	}
	//TODO: array function pointer
	//inst[core->memory(GET_ADRESS(process.pc))](core, process);
	set_process_counter(process);
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
