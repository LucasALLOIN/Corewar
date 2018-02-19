/*
** EPITECH PROJECT, 2017
** sources/utils/free_it.c
** File description:
**
*/

#include <stdlib.h>

void free_it(char **pointer)
{
	free(*pointer);
}