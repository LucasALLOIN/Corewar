/*
** EPITECH PROJECT, 2017
** sources/utils/memory/my_memcpy.c
** File description:
** my_memcpy function's file
*/

#include "unistd.h"
#include "corewar.h"
#include "op.h"
#include "my_printf.h"
#include "utils.h"

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
	write(1, "0x000000 : ", 11);
	for (int i = 1; i <= MEM_SIZE; ++i) {
		if (!memory[i - 1])
			my_printf("%#04x ", memory[i - 1]);
		else
			my_printf("\e[1;32m%#04x \e[0m", memory[i - 1]);
		if ((i % (MEM_SIZE / 500)) == 0)
			my_printf("\n%#08x : ", i - 1);
	}
}
