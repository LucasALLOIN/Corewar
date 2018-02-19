/*
** EPITECH PROJECT, 2017
** sources/utils/find_next.c
** File description:
**
*/

#include "utils.h"

int find_next(char const *mem, char c)
{
	for (int i = 0; i < my_strlen(mem); i++) {
		if (mem[i] == c) {
			return (i);
		}
	}
	return (-1);
}