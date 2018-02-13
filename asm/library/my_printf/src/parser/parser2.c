/*
** EPITECH PROJECT, 2017
** parser2.c
** File description:
** second part of the parser functions
*/

#include "my_printf.h"

int ok_test(arg_option_t *arg_option)
{
	if (arg_option->conv_type == '\0')
		return (84);
	return (0);
}

void nbr_detect(const char *format, arg_option_t *arg_option, int *i)
{
	if (format[*i] == '*')
		arg_option->star = 1;
	if (!arg_option->precision && arg_option->width == 0)
		arg_option->width = my_getnbr((char *) (format + *i));
}
