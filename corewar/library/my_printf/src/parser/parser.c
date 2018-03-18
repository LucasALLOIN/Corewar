/*
** EPITECH PROJECT, 2017
** parser.c
** File description:
** parser for my_printf
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_printf.h"
#include "const.h"

static void get_flags(char c, arg_option_t *arg_option)
{
	switch (c) {
	case '#':
		arg_option->diese = 1;
		break;
	case '0':
		arg_option->zero = 1;
		break;
	case ' ':
		arg_option->space = 1;
		break;
	case '-':
		arg_option->minus = 1;
		break;
	case '+':
		arg_option->plus = 1;
		break;
	}
}

static int get_length (const char *format, int *i)
{
	if (format[*i] == 'h')
		if (format[*i + 1] == 'h')
			return (1);
		else
			return (2);
	else if (format[*i] == 'l')
		if (format[*i + 1] == 'l')
			return (4);
		else
			return (3);
	return (-1);
}

static void dot_test(const char *format, int i, arg_option_t *arg_opt)
{
	if ((i > 0) && (format[i - 1] == '.')) {
		arg_opt->presize = my_getnbr((char *) format + i);
		arg_opt->precision = 1;
	} else
		arg_opt->presize = 0;
}

static void check_formats(const char *format, arg_option_t *arg_option, int *i)
{
	int bl = 0;

	(*i)++;
	while (!is_in((char *) &format[*i], (char *) CONV) &&
		(format[*i] != '\0' && format[*i] != '%')) {
		if (is_in((char *) &format[*i], (char *)FLAGS) && bl == 0) {
			get_flags(format[*i], arg_option);
			dot_test(format, *i, arg_option);
		} else if (is_in((char *) &format[*i], (char *) NBR) ||
			format[*i] == '*') {
			dot_test(format, *i, arg_option);
			nbr_detect(format, arg_option, i);
			bl += 1;
		} else if ((format[*i] == 'h' || format[*i] == 'l') &&
			arg_option->len_mod == 0)
			arg_option->len_mod = get_length(format, i);
		(*i)++;
	}
	arg_option->conv_type = (format[*i] == '\0' || format[*i] == '%') ?
		'e' : format[*i];
}

int parser(const char *format, arg_option_t **arg_option, int size)
{
	int i = 0;
	int counter = 0;

	while (counter < size && format[i] != '\0') {
		if (format[i] == '%' && format[i + 1] != '%') {
			check_formats(format, arg_option[counter], &i);
			counter++;
			i = (format[i] == '\0' || format[i] == '%') ?
				i - 1 : i;
		} else if (format[i] == '%' && format[i + 1] == '%')
			i++;
		i++;
	}
}
