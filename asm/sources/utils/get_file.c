/*
** EPITECH PROJECT, 2017
** sources/utils/get_file.c
** File description:
** get an entire file
*/

#include <stdlib.h>
#include "utils.h"

char *get_file(int fd)
{
	char *file = 0x0;
	char *temp = get_next_line(fd);
	char *cleaned_temp = 0x0;

	while (temp) {
		cleaned_temp = clean_str(temp);
		free(temp);
		temp = my_strcat(cleaned_temp, "\n");
		if (my_strlen(temp) > 1 && temp[0] != '#') {
			file = my_strcat(file, temp);
		}
		free(temp);
		temp = get_next_line(fd);
	}
	return (file);
}