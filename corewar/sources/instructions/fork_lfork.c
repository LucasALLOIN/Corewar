/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function of the corewar
*/

#include <stdlib.h>
#include "op.h"
#include "corewar.h"
#include "instructions.h"
#include "my_printf.h"
#include "mem_manage.h"
#include "utils.h"

static void gnpi_util(process_t *process, int *val)
{
	while (process != NULL) {
		if (process->id > *val)
			*val = process->id;
		process = process->next;
	}
}

int get_next_process_id(core_t *core)
{
	int val = 0;

	for (int i = 0; i < core->nb_progs; i++) {
		gnpi_util(core->program_tab[i].process_l, &val);
	}
	return (val + 1);
}

static void dup_registers(process_t *old, process_t *new)
{
	for (int i = 0; i < REG_NUMBER; i++) {
		for (int y = 0; y < REG_SIZE; y++) {
			new->registers[i][y] = old->registers[i][y];
		}
	}
}

void dup_process(process_t *process, int newpc, int id)
{
	process_t *new_node = my_calloc(sizeof(process_t));
	process_t *tmp = process;

        dup_registers(process, new_node);
	new_node->load_adress = process->load_adress;
	new_node->turn_to_exec = process->turn_to_exec;
	new_node->was_waiting = process->was_waiting;
	new_node->pc = newpc;
	new_node->id = id;
	new_node->carry = process->carry;
	new_node->parent = process->parent;
	new_node->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
}
