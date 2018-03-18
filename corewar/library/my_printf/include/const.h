/*
** EPITECH PROJECT, 2017
** const.h
** File description:
** header of global const
*/

#ifndef CONST_H_
#define CONST_H_

static const char *CONV   = "diuoxXpbcsS";
static const char *FLAGS  = "#0+- ";
static const char *NBR    = "123456789";
static const char *INT    = "dioxXbcu";
static const char *STR    = "sS";

static const void (*PRINT_INT[8]) (long long) = {&my_putnbr, &my_putnbr,
						&my_putnbr_octal,
						&my_putnbr_hexa,
						&my_putnbr_hexa_upper,
						&my_putnbr_binary,
						&my_putchar,
						&my_putunsigned};

static const void (*PRINT_STR[2]) (char *, int, int) = {&my_putstr_sized,
							&my_show_str};

#endif /* CONST_H_ */
