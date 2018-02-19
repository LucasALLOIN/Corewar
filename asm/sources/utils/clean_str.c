/*
** EPITECH PROJECT, 2018
** clear_str.c
** File description:
** Functions for the project clear_str
*/

#include <unistd.h>
#include "utils.h"

static int has_sole_spaces(char const *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

char *clean_str(char const *str)
{
	char *result = my_calloc(my_strlen(str) + 1);
	int counter = 0;
	int is_spaced = 1;
	int i = 0;

	while (str[i]) {
		if (!is_spaced && (str[i] == ' ' || str[i] == '\t')) {
			is_spaced = 1;
			result[counter] = ' ';
			counter++;
		} else if (str[i] != ' ' && str[i] != '\t') {
			result[counter] = str[i];
			counter++;
			is_spaced = has_sole_spaces(str + i + 1) ? 1 : 0;
		}
		i++;
	}
	return (result);
}
