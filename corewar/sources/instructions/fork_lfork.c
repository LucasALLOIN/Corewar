/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function of the corewar
*/

#include <stdlib.h>
#include "corewar.h"
#include "instructions.h"
#include "my_printf.h"
#include "mem_manage.h"
#include "utils.h"

void copy_data(byte_t *data, byte_t *data2, size_t size)
{
	size_t i = 0;

	while (i < size) {
		data[i] = data2[i];
		i = i + 1;
	}
	return;
}

int get_max_id_of_process(process_t *process)
{
	int ret = 0;

	if (process->next != NULL) {
		ret = get_max_id_of_process(process->next);
		if (process->id < ret)
			return (ret);
	}
	return (process->id);
}

int get_max_id(program_t **programme)
{
	program_t *program = *programme;
	int i = 0;
	int my_ret = 0;
	int ret = 0;

	while (i < MAX_ARGS_NUMBER) {
		ret = get_max_id_of_process(program[i].process_l);
		if (my_ret < ret)
			my_ret = ret;
		i = i + 1;
	}
	return (my_ret);
}

void dump_process_lfork(int id, core_t *core, int value, process_t *process)
{
	byte_t *owner_table = (core->owner_table);
	byte_t *memory = (core->memory);
	int i = 0;
	process_t *new = malloc(sizeof(process_t));
	
	copy_data((byte_t *) new, (byte_t *) process, sizeof(process_t));
	process->next = new;
	new->pc += value;
	new->id = get_max_id((program_t **) &(core->program_tab)) + 1;

	while (i < MEM_SIZE) {
		if (owner_table[i] == id) {
			memory[ADRESS(i + value)] = memory[i];
			owner_table[ADRESS(i + value)] = new->id;
		}
		i += 1;
	}
	return;
}

void dump_process_fork(int id, core_t *core, int value, process_t *process)
{
	byte_t *owner_table = (core->owner_table);
	byte_t *memory = (core->memory);
	int i = 0;
	process_t *new = malloc(sizeof(process_t));
	
	copy_data((byte_t *) new, (byte_t *) process, sizeof(process_t));
	process->next = new;
	new->pc += value % IDX_MOD;
	new->id = get_max_id((program_t **) &(core->program_tab)) + 1;
	while (i < MEM_SIZE) {
		if (owner_table[i] == id) {
			memory[ADRESS(i + (value % IDX_MOD))] = memory[i];
			owner_table[ADRESS(i + (value % IDX_MOD))] = new->id;
		}
		i += 1;
	}
	return;
}

