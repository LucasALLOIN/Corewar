/*
** EPITECH PROJECT, 2017
** flags_functions.c
** File description:
** function wrapper for flags
*/

#include "my_printf.h"
#include "const.h"

static void plus_space_it(arg_option_t *arg_opt, long long nbr)
{
	if (arg_opt->conv_type == 'd' || arg_opt->conv_type == 'i') {
		if (arg_opt->plus == 1 && nbr > 0)
			my_putchar('+');
		else if (arg_opt->space == 1 && nbr > 0)
			my_putchar(' ');
	}
}

static void diese_it(arg_option_t *arg_opt)
{
	if (arg_opt->diese == 1 && arg_opt->conv_type == 'o') {
		my_putchar('0');
	} else if (arg_opt->diese == 1 && arg_opt->conv_type == 'x') {
		my_putchar('0');
		my_putchar('x');
	} else if (arg_opt->diese == 1 && arg_opt->conv_type == 'X') {
		my_putchar('0');
		my_putchar('X');
	}
}

static void pad_it(arg_option_t *arg_opt, long long nbr)
{
	char pad_char = ((arg_opt->zero && arg_opt->minus == 0) == 1 ?
			'0' : ' ');
	int size_nb = get_sizenb(nbr, arg_opt->conv_type);
	int pad_size = arg_opt->width - size_nb;
	int iter = 0;

	if (arg_opt->plus == 1 || arg_opt->space == 1)
		pad_size--;
	if (arg_opt->diese == 1 && arg_opt->conv_type == 'o')
		pad_size--;
	if (arg_opt->diese == 1 && (arg_opt->conv_type == 'x' ||
				arg_opt->conv_type == 'X'))
		pad_size -= 2;
	while (iter < pad_size) {
		my_putchar(pad_char);
		iter++;
	}
}

static int print_type(long long nbr, arg_option_t *arg_opt, int i)
{
	if (arg_opt->conv_type == 'u')
		arg_opt->len_mod = 4;
	switch (arg_opt->len_mod) {
	case 0:
		nbr = (int) nbr;
		break;
	case 1:
		nbr = (char) nbr;
		break;
	case 2:
		nbr = (short) nbr;
		break;
	case 3:
		nbr = (long) nbr;
		break;
	case 4:
		nbr = (long long) nbr;
		break;
	};
	PRINT_INT[i](nbr);
}

void flag_it(long long nbr, arg_option_t *arg_opt, int i)
{
	if (arg_opt->conv_type != 'e')
		if (arg_opt->minus != 1) {
			diese_it(arg_opt);
			pad_it(arg_opt, nbr);
			plus_space_it(arg_opt, nbr);
			print_type(nbr, arg_opt, i);
		} else if (arg_opt->minus == 1) {
			plus_space_it(arg_opt, nbr);
			diese_it(arg_opt);
			print_type(nbr, arg_opt, i);
			pad_it(arg_opt, nbr);
		}
}
