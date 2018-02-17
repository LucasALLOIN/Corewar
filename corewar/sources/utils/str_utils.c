/*
** EPITECH PROJECT, 2018
** str_utils.c
** File description:
** str functions
*/

#include "utils.h"
#include "my_printf.h"

int my_strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
		i++;
	}
	if (str1[i] == str2[i])
		return (1);
	else
		return (0);
}

char *my_strdup(const char *str)
{
	int i = -1;
	char *new_str = my_calloc(sizeof(char) * (my_strlen((char *)str) + 1));

	while (str[++i])
		new_str[i] = str[i];
	new_str[i] = '\0';
	return (new_str);
}

char *my_strcat(char *dest, char *str)
{
	int i = 0;
	int j = 0;

	for (i = 0; dest[i] != '\0'; i++)
		;
	if (i > 0 && str[0] == '/' && dest[i - 1] == '/')
		return (dest);
	for (j = 0; str[j] != '\0'; j++)
		dest[i + j] = str[j];
	dest[i + j] = 0;
	return (dest);
}

char *my_strcpy(char *dest, char *str)
{
	int i = 0;

	while (str[i]) {
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
