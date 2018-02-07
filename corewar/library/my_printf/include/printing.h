/*
** EPITECH PROJECT, 2017
** printing.h
** File description:
** header of printing functions
*/

#ifndef PRINTING_H_
#define PRINTING_H_

int my_strlen(char *str);
void my_putchar(long long c);
void my_putstr(char *str);
void my_putnbr(long long nb);
void my_show_str(char *str, int precision, int size);
void my_putstr(char *str);
void my_putstr_sized(char *str, int precision, int size);
void my_print_pointer(void *ptr);
void my_putnbr_octal(long long nb);
void my_putnbr_hexa(long long nb);
void my_putnbr_hexa_upper(long long nb);
void my_putnbr_binary(long long nb);
void my_putunsigned(long long nb);
void put_zeros(char c);
void my_putstr_error(char *str);

#endif /* PRINTING_H_ */
