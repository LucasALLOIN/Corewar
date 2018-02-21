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

void int_to_uchar(core_t *core, int nb, int start)
{
	mem_int_t mem_int = {.nb = nb};

	core->memory[ADRESS(start)] = mem_int.byte[3];
        core->memory[ADRESS(start + 1)] = mem_int.byte[2];
	core->memory[ADRESS(start + 2)] = mem_int.byte[1];
        core->memory[ADRESS(start + 3)] = mem_int.byte[0];
}

int uchar_to_int(core_t *core, int start)
{
	mem_int_t mem_int;

	mem_int.byte[0] = core->memory[ADRESS(start + 3)];
	mem_int.byte[1] = core->memory[ADRESS(start + 2)];
	mem_int.byte[2] = core->memory[ADRESS(start + 1)];
	mem_int.byte[3] = core->memory[ADRESS(start)];
	return (mem_int.nb);
}

void short_to_uchar(core_t *core, short nb, int start)
{
	mem_short_t mem_short = {.nb = nb};

        core->memory[ADRESS(start)] = mem_short.byte[1];
	core->memory[ADRESS(start + 1)] = mem_short.byte[0];
}

short uchar_to_short(core_t *core, int start)
{
	mem_short_t mem_short;
	mem_short.byte[0] = core->memory[ADRESS(start + 1)];
	mem_short.byte[1] = core->memory[ADRESS(start)];
	return (mem_short.nb);
}
