/*
** EPITECH PROJECT, 2017
** sources/utils/memory/my_memcpy.c
** File description:
** my_memcpy function's file
*/

#include "corewar.h"
#include "op.h"

void my_memcpy(void *mem_dest, const void *mem_src, int len)
{
	while (len) {
		*((unsigned char*)mem_dest) = *((unsigned char*)mem_src);
		(unsigned char*)mem_dest++;
		(unsigned char*)mem_src++;
		len--;
	}
}

void dump_virtual_mem(byte_t memory[])
{
	for (int i = 0; i < MEM_SIZE; ++i) {
		my_printf("0x0%d", memory[i]);
		if (i && (i % 20) == 0)
			write(1, "\n", 1);
	}
}
