/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** str len
*/

int my_strlen(const char *str)
{
	int len = 0;

	for (; str[len]; len++);
	return (len);
}
