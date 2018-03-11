/*
** EPITECH PROJECT, 2017
** sources/utils/my_memcmp.c
** File description:
** My_memcmp
*/

#include "utils.h"

int my_memcmp(void const *memblk1, void const *memblk2)
{
	for (int i = 0; ((char *)memblk1)[i] && ((char *)memblk2)[i]; i++) {
		if (((char *)memblk1)[i] != ((char *)memblk2)[i])
			return (0);
	}
	return (my_strlen(memblk1) == my_strlen(memblk2));
}

int my_memncmp(void const *mem1, void const *mem2, int n)
{
	for (int i = 0; i < n && ((char *)mem1)[i] && ((char *)mem2)[i]; i++) {
		if (((char *)mem1)[i] != ((char *)mem2)[i])
			return (0);
	}
	return (1);
}
