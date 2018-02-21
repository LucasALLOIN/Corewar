/*
** EPITECH PROJECT, 2017
** print_unsigned.c
** File description:
** print unsigned value
*/

#include <limits.h>
#include "printing.h"

void my_putunsigned(long long nb)
{
	if (nb < 0)
		nb = UINT_MAX - nb;
	if (nb >= 10)
		my_putunsigned(nb / 10);
	my_putchar((nb % 10) + 48);
}
