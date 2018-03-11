/*
** EPITECH PROJECT, 2017
** sources/utils/my_strcat.c
** File description:
** concatenation
*/

#include <stdlib.h>
#include "utils.h"

void my_memcpy(void *mem_dest, const void *mem_src, int len)
{
	while (len) {
		*((unsigned char *)mem_dest) = *((unsigned char *)mem_src);
		(unsigned char *)mem_dest++;
		(unsigned char *)mem_src++;
		len--;
	}
}

char *my_strcat(char *src1, char *src2)
{
	int len1 = src1 ? my_strlen(src1) : 0;
	int len2 = src2 ? my_strlen(src2) : 0;
	char *result = my_calloc(len1 + len2);

	my_memcpy(result, src1, len1);
	my_memcpy(result + len1, src2, len2);
	free(src1);
	return (result);
}

char *append(char *src, char c)
{
	char *result = my_calloc(my_strlen(src) + 1);

	my_memcpy(result, src, my_strlen(src));
	my_memcpy(result + my_strlen(src), &c, 1);
	free(src);
	return (result);
}