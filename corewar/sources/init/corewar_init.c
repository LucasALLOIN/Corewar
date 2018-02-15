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

int get_offset(int nbr)
{

}

static int load_memory(process_t process, byte_t memory[])
{
	static int nb = 0;
	char *buffer = my_calloc(process.header.prog_size);
	int offset = 0;

	for (int x = 0; x < i; x++)
		prog_space += core->process_tab[x].header.prog_size;
	return (prog_space + separator);
}

static int load_memory(process_t process, core_t *core, int free_mem, int i)
{
        int adress = 0;

        if (i != 0)
		adress = get_load_adress(core, free_mem, i);
	else
		adress = 0;
	process.load_adress = adress;
#ifdef DEBUG_MODE
	my_printf("=============== CHAMPION %s LOADING ================\n\n", \
	process.header.prog_name);
	my_printf("Adress: %d\nProg_size: %d\nMEM_SIZE %d\n\n", \
	adress, process.header.prog_size, MEM_SIZE);
#endif
	if (read(process.fd, &core->memory[adress], process.header.prog_size) == -1)
		return (84);
	//TODO: alloin fait la fonction get offset stp qui \
	retourne la taille en fonction du num du process\n
	offset = get_offset(nb);
	offset = 0;     		//TODO: remove this line
	my_memcpy(memory, buffer + offset, process.header.prog_size);
	my_printf("allo\n");
	dump_virtual_mem(memory);
	nb++;
	return (0);
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
