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

void int_to_uchar(int nb, byte_t *byte)
{
	mem_int_t mem_int = {.nb = nb};

	byte[0] = mem_int.byte[3];
	byte[1] = mem_int.byte[2];
	byte[2] = mem_int.byte[1];
	byte[3] = mem_int.byte[0];
}

int uchar_to_int(byte_t *byte)
{
	mem_int_t mem_int;

	mem_int.byte[0] = byte[3];
	mem_int.byte[1] = byte[2];
	mem_int.byte[2] = byte[1];
	mem_int.byte[3] = byte[0];
	return (mem_int.nb);
}

void short_to_uchar(short nb, byte_t *byte)
{
	mem_short_t mem_short = {.nb = nb};

	byte[0] = mem_short.byte[1];
	byte[1] = mem_short.byte[0];
}

short uchar_to_short(byte_t *byte)
{
	mem_short_t mem_short;

	mem_short.byte[0] = byte[1];
	mem_short.byte[1] = byte[0];
	return (mem_short.nb);
}
