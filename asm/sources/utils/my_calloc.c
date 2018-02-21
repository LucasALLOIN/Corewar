/*
** EPITECH PROJECT, 2017
** source/utils/memory.c
** File description:
** my_calloc function's file
*/

#include <stdlib.h>
#include "utils.h"

void *my_calloc(int size)
{
	void *data = malloc(size + 1);
	char *temp = data;

	if (!data)
		return (NULL);
	while (size + 1) {
		*(temp) = 0;
		temp++;
		size--;
	}
	return (data);
}
