/*
** EPITECH PROJECT, 2017
** printing_base.c
** File description:
** display nbr_base
*/

#include <unistd.h>
#include "printing.h"

void my_putnbr_octal(long long nb)
{
	char base[] = "01234567";

	if (nb < 0) {
		my_putchar('-');
		nb = - nb;
	}
	if (nb >= 8)
		my_putnbr_octal(nb / 8);
	my_putchar(base[nb % 8]);
}

void my_putnbr(long long nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = - nb;
	}
	if (nb >= 10)
		my_putnbr(nb / 10);
	my_putchar((nb % 10) + 48);
}

void my_putnbr_binary(long long nb)
{
	char base[] = "01";

	if (nb < 0) {
		my_putchar('-');
		nb = - nb;
	}
	if (nb >= 2)
		my_putnbr_binary(nb / 2);
	my_putchar(base[nb % 2]);
}

void my_putnbr_hexa_upper(long long nb)
{
	char base[] = "0123456789ABCDEF";

	if (nb < 0) {
		my_putchar('-');
		nb = - nb;
	}
	if (nb >= 16)
		my_putnbr_hexa_upper(nb / 16);
	my_putchar(base[nb % 16]);
}

void my_putnbr_hexa(long long nb)
{
	char base[] = "0123456789abcdef";

	if (nb < 0) {
		my_putchar('-');
		nb = - nb;
	}
	if (nb >= 16)
		my_putnbr_hexa(nb / 16);
	my_putchar(base[nb % 16]);
}
