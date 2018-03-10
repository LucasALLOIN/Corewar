/*
** EPITECH PROJECT, 2017
** sources/utils/my_memcmp.c
** File description:
** My_memcmp
*/

#include "utils.h"

int my_memcmp(void const *memblock1, void const *memblock2)
{
	for (int i = 0; ((char*)memblock1)[i] && ((char*)memblock2)[i]; i++) {
		if (((char*)memblock1)[i] != ((char*)memblock2)[i])
			return (0);
	}
	return (my_strlen(memblock1) == my_strlen(memblock2));
}

int my_memncmp(void const *memblock1, void const *memblock2, int n)
{
	for (int i = 0; i < n && ((char*)memblock1)[i] && ((char*)memblock2)[i]; i++) {
		if (((char*)memblock1)[i] != ((char*)memblock2)[i])
			return (0);
	}
	return (1);
}
