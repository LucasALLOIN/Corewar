/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** utils functions
*/

#include <unistd.h>
#include "printing.h"
#include "const.h"

int is_in(char *is, char *in)
{
	int i = 0;
	int size = my_strlen(in);
	int ret = 0;

	while (i < size) {
		if (*is == in[i])
			return (1);
		i++;
	}
	return (0);
}

int my_format_len(const char *format, int i)
{
	int j = 0;
	char *temp = (char *) format;

	temp += i;
	while (!is_in(temp + j, (char *) CONV))
		j++;
	return (j);
}

int get_sizenb(long long nb, char type)
{
	int i = 0;
	int diviseur = 10;

	if (type == 'o')
		diviseur = 8;
	else if (type == 'b')
		diviseur = 2;
	else if (type == 'x' || type == 'X')
		diviseur = 16;
	while (nb / diviseur > 0) {
		nb /= diviseur;
		i++;
	}
	return (type == 'c' ? 1 : i + 1);
}

int my_getnbr(char *format)
{
	int i = 0;
	int res = 0;

	while (format[i] >= '0' && format[i] <= '9') {
		res *= 10;
		res += (format[i++] - 48);
	}
	return (res);
}

void my_putstr_error(char *str)
{
	int i = 0;

	while (str[i])
		write(2, &str[i++], 1);
}
