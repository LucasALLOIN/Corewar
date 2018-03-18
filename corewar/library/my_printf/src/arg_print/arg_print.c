/*
** EPITECH PROJECT, 2017
** arg_print.c
** File description:
** argument printing functions
*/

#include <stdarg.h>
#include "my_printf.h"
#include "const.h"

void print_good_type(va_list var, arg_option_t *arg_opt, int i)
{
	if (arg_opt->star == 1)
		arg_opt->width = va_arg(var, int);
	flag_it(va_arg(var, long long), arg_opt, i);
}

void print_others(va_list var, arg_option_t *arg_opt)
{
	int i = 0;

	if (is_in(&(arg_opt->conv_type), (char *) INT)) {
		while (arg_opt->conv_type != INT[i])
			i++;
		print_good_type(var, arg_opt, i);
	} else if (is_in(&(arg_opt->conv_type), (char *) STR)) {
		while (arg_opt->conv_type != STR[i])
			i++;
		PRINT_STR[i](va_arg(var, char *), arg_opt->precision,
			arg_opt->presize);
	}
}

void print_arg(va_list var, arg_option_t *arg_opt)
{
	if (arg_opt->conv_type == 'p')
		my_print_pointer((void *) va_arg(var, void *));
	else
		print_others(var, arg_opt);
}
