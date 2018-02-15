/*
** EPITECH PROJECT, 2017
** my_printf.h
** File description:
** header of printf functions
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>
#include "printing.h"

typedef struct arg_option {
	int diese;
	int zero;
	int plus;
	int minus;
	int space;
	int width;
	int len_mod  ;
	int precision;
	int presize;
	int star;
	char conv_type;
} arg_option_t;

int my_printf(const char *format, ...);
int is_in(char *is, char *in);
int my_getnbr(char *format);
int my_format_len(const char *format, int i);
int get_sizenb(long long nb, char type);
int parser(const char *format, arg_option_t *arg_option[], int size);
void print_arg(va_list var, arg_option_t *arg_opt);
arg_option_t *init_arg(void);
arg_option_t **alloc_all_arg(int size);
void free_all_arg(arg_option_t **arg, int size);
void flag_it(long long nbr, arg_option_t *arg_opt, int i);
void nbr_detect(const char *format, arg_option_t *arg_option, int *i);
int ok_test(arg_option_t *arg_option);

#endif /* MY_PRINTF_H_ */
