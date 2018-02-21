/*
** EPITECH PROJECT, 2017
** printing.c
** File description:
** display type
*/

#include <unistd.h>
#include "printing.h"

void my_putstr(char *str)
{
	int size = my_strlen(str);

	write(1, str, size);
}

void my_putstr_sized(char *str, int precision, int size)
{
	int i = 0;

	if (!precision)
		size = my_strlen(str) + 1;
	while (str[i] && (i < size))
		my_putchar(str[i++]);
}

void my_print_pointer(void *ptr)
{
	long long value_ptr = (long long) ptr;

	if (ptr == NULL)
		my_putstr("(nil)");
	else {
		my_putchar('0');
		my_putchar('x');
		my_putnbr_hexa(value_ptr);
	}
}

void my_show_str(char *str, int precision, int size)
{
	int i = 0;

	if (!precision)
		size = my_strlen(str) + 1;
	while (str[i] && (i < size)) {
		if (str[i] < 32 || str[i] == 127) {
			my_putchar('\\');
			put_zeros(str[i]);
			my_putnbr_octal(str[i]);
		} else
			my_putchar(str[i]);
		i++;
	}
}
