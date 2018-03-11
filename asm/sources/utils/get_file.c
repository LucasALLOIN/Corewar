/*
** EPITECH PROJECT, 2017
** sources/utils/get_file.c
** File description:
** get an entire file
*/

#include <stdlib.h>
#include "utils.h"

static char *my_strdup(char const *str)
{
	char *new = my_calloc(my_strlen(str) + 1);

	my_memcpy(new, str, my_strlen(str));
	return (new);
}

char *get_file(int fd)
{
	char *file = 0x0;
	char *temp = get_next_line(fd);
	char *cleaned_temp = 0x0;

	while (temp) {
		if (!match(temp, ".name*") && !match(temp, ".comment*")) {
			cleaned_temp = clean_str(temp);
			free(temp);
		} else {
			cleaned_temp = my_strdup(temp);
			free(temp);
		}
		temp = my_strcat(cleaned_temp, "\n");
		file = my_strcat(file, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	return (file);
}