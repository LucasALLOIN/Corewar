/*
** EPITECH PROJECT, 2017
** struct_func.c
** File description:
** struct fuctions
*/

#include <stdlib.h>
#include "my_printf.h"

arg_option_t *init_arg(void)
{
	arg_option_t *arg_opt = malloc(sizeof(arg_option_t));

	arg_opt->diese = 0;
	arg_opt->zero = 0;
	arg_opt->plus = 0;
	arg_opt->minus = 0;
	arg_opt->space = 0;
	arg_opt->width = 0;
	arg_opt->len_mod = 0;
	arg_opt->precision = 0;
	arg_opt->presize = 0;
	arg_opt->star = 0;
	arg_opt->conv_type = 0;
	return (arg_opt);
}

arg_option_t **alloc_all_arg(int size)
{
	int i = 0;
	arg_option_t **args = malloc(sizeof(arg_option_t*) * size);

	while (i < size)
		args[i++] = init_arg();
	return (args);
}

void free_all_arg(arg_option_t **arg, int size)
{
	int i = 0;

	while (i < size)
		free(arg[i++]);
	free(arg);
}
