/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** printf function !
*/

#include <stdarg.h>
#include "my_printf.h"
#include "const.h"

static int get_nbarg(const char *format)
{
	int count = 0;
	int i = 0;

	while (format[i]) {
		if (format[i] == '%' && format[i + 1] != '%') {
			count++;
		} else if (format[i] == '%' && format[i + 1] == '%') {
			i++;
		}
		i++;
	}
	return (count);
}

static void jump_arg(int *iter, arg_option_t **arg_option, va_list variables,
		     const char *format)
{
	if (arg_option[iter[1]]->conv_type == 'e') {
		my_putchar(format[iter[0]]);
		(iter[1])++;
	} else {
		print_arg(variables, arg_option[(iter[1])++]);
		iter[0] += my_format_len(format, iter[0]);
	}
}

int my_print_str(const char *format, arg_option_t **arg_option,
		 va_list variables)
{
	int ret_count = 0;
	int iter[2] = {0, 0};

	while (format[iter[0]]) {
		if (format[iter[0]] == '%' && format[iter[0] + 1] != '%') {
			jump_arg(iter, arg_option, variables, format);
		} else {
			iter[0] = (format[iter[0]] == '%') ?
				iter[0] + 1 : iter[0];
			my_putchar(format[iter[0]]);
		}
		iter[0]++;
	}
	return (ret_count);
}

static void my_putformat(const char *format)
{
	int i = 0;

	while (format[i]) {
		if (format[i] == '%')
			i++;
		my_putchar(format[i]);
		i++;
	}
}

int my_printf(const char *format, ...)
{
	va_list variables;
	int nb_arg = get_nbarg(format);
	int nb_pchar = 0;
	arg_option_t **arg_option = alloc_all_arg(nb_arg);

	if (nb_arg == 0) {
		my_putformat(format);
		free_all_arg(arg_option, nb_arg);
		return (0);
	}
	va_start(variables, format);
	parser(format, arg_option, nb_arg);
	my_print_str(format, arg_option, variables);
	va_end(variables);
	free_all_arg(arg_option, nb_arg);
	return (nb_pchar);
}
