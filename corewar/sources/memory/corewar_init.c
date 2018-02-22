/*
** EPITECH PROJECT, 2017
** corewar_init.c
** File description:
** initialisation of the file
*/

#include "unistd.h"
#include "corewar.h"
#include "utils.h"
#include "my_printf.h"
#include "mem_manage.h"

int get_load_adress(core_t *core, int free_mem, int i)
{
	int separator = (free_mem / core->nb_progs) * i;
	int prog_space = 0;

	if (!i)
		return (0);
	for (int x = 0; x < i; x++)
		prog_space += core->program_tab[x].header.prog_size;
	return (prog_space + separator);
}


static int load_memory(process_t *process, core_t *core, int free_mem, int i)
{
	if (process->load_adress == -1) {
		core->program_tab[i].process_l->load_adress = \
		get_load_adress(core, free_mem, i);
	}
        process->pc = process->load_adress;
	core->program_tab[i].number = i;
	int_to_reg(i, process->registers[0]);
	process->carry = 0;
	core->program_tab[i].is_alive = 1;
	core->program_tab[i].last_live_cycle = -1;
#ifdef DEBUG_MODE
	my_printf("=============== CHAMPION %s LOADING ================\n\n", \
	core->program_tab[i].header.prog_name);
	my_printf("Adress: %d\nProg_size: %d\nPC %d\n\n", \
	process->load_adress, core->program_tab[i].header.prog_size, process->pc);
#endif
	if (read(core->program_tab[i].fd, &core->memory[process->load_adress], core->program_tab[i].header.prog_size) == -1)
		return (84);
	return (0);
}

int total_size(core_t *core)
{
	int res = 0;

	for (int i = 0; i  < core->nb_progs; ++i)
		res += core->program_tab[i].header.prog_size;
	return (res);
}

void set_owner_table(core_t *core, process_t *process)
{
	my_printf("%d %d\n", process->parent->header.prog_size, process->load_adress);
        for (int i = 0; i < process->parent->header.prog_size; i++) {
		core->owner_table[i + process->load_adress] = process->id;
	}
}

int corewar_init(core_t *core)
{
	int b_size = total_size(core);

	for (int i = 0; i < core->nb_progs; ++i) {
		load_memory(core->program_tab[i].process_l, core, MEM_SIZE - b_size, i);
		core->program_tab[i].process_l->parent = &core->program_tab[i];
		set_owner_table(core, core->program_tab[i].process_l);
	}
#ifdef DEBUG_MODE
	my_printf("===== MEMORY DUMP AFTER CHAMPION INJECTION =====\n\n");
	dump_virtual_mem_color(core->memory, core->owner_table);
#endif
	return (0);
}
