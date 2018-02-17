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
		prog_space += core->process_tab[x].header.prog_size;
	return (prog_space + separator);
}

static int load_memory(process_t process, core_t *core, int free_mem, int i)
{
	int adress = 0;

	if (process.load_adress == -1) {
		core->process_tab[i].load_adress = \
		get_load_adress(core, free_mem, i);
		core->process_tab[i].pc = core->process_tab[i].load_adress;
		core->process_tab[i].number = i;
		int_to_uchar(i, core->process_tab[i].registers[0]);
	}
#ifdef DEBUG_MODE
	my_printf("=============== CHAMPION %s LOADING ================\n\n", \
	process.header.prog_name);
	my_printf("Adress: %d\nProg_size: %d\nPC %d\n\n", \
	process.load_adress, process.header.prog_size, process.pc);
#endif
	if (read(process.fd, &core->memory[core->process_tab[i].load_adress], process.header.prog_size) == -1)
		return (84);
	return (0);
}

int total_size(core_t *core)
{
	int res = 0;

	for (int i = 0; i  < core->nb_progs; ++i)
		res += core->process_tab[i].header.prog_size;
	return (res);
}

int corewar_init(core_t *core)
{
	int b_size = total_size(core);

	for (int i = 0; i < core->nb_progs; ++i)
		load_memory(core->process_tab[i], core, MEM_SIZE - b_size, i);
#ifdef DEBUG_MODE
	my_printf("===== MEMORY DUMP AFTER CHAMPION INJECTION =====\n\n");
	dump_virtual_mem(core->memory);
#endif
	return (0);
}
