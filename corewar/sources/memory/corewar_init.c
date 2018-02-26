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


static int load_memory(process_t *process, core_t *core, int f_mem, int i)
{
	program_t *prog = &core->program_tab[i];

	if (process->load_adress == -1)
		prog->process_l->load_adress = get_load_adress(core, f_mem, i);
        process->pc = process->load_adress;
	prog->number = i + 1;
	int_to_reg(i, process->registers[0]);
	process->carry = 0;
	prog->is_alive = 1;
	prog->last_live_cycle = -1;
	if (process->load_adress + prog->header.prog_size > MEM_SIZE) { 
		if (read(prog->fd, &core->memory[process->load_adress], 	    \
		    	 MEM_SIZE - process->load_adress + 1)  == -1 ||
		    read(prog->fd, &core->memory[0], prog->header.prog_size - \
			 (MEM_SIZE - process->load_adress + 1) == -1))
			return (84);
	} else
		if (read(prog->fd, &core->memory[process->load_adress],      \
			 prog->header.prog_size) == -1)
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
	int offset = 0;

	my_printf("%d %d\n", process->parent->header.prog_size, process->load_adress);
	my_printf("Process id: %d\n", process->id);
        for (int i = 0; i < process->parent->header.prog_size; i++) {
		if (!offset && process->load_adress + i >= MEM_SIZE)
			offset = process->load_adress + i;
		core->owner_table[i + process->load_adress - offset] = process->id;
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
	dump_virtual_mem_color(core->memory, core->owner_table, core);
#endif
	return (0);
}
