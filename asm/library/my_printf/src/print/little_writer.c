/*
** EPITECH PROJECT, 2017
** little_writer.c
** File description:
** little functions that help other
*/

#include <unistd.h>
#include "printing.h"

void my_putchar(long long c)
{
	write(1, &c, 1);
}

void put_zeros(char c)
{
	if (c == 0)
		my_putstr("000");
	else if (c < 8)
		my_putstr("00");
	else if (c < 64)
		my_putchar('0');
}
