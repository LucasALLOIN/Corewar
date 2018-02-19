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
	char *file = "";
	char *temp = get_next_line(fd);

	while (temp) {
		temp = clean_str(temp);
		if (my_strlen(temp) && temp[0] != '#') {
			file = my_strlen(file) ? append(file, '\n') : file;
			file = my_strcat(file, temp);
		}
		free(temp);
		temp = get_next_line(fd);
	}
	return (file);
}