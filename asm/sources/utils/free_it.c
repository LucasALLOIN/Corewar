/*
** EPITECH PROJECT, 2017
** sources/utils/free_it.c
** File description:
** Free
*/

#include <stdlib.h>
#include "asm.h"

void free_it(char **pointer)
{
	free(*pointer);
}

void free_array(char ***array)
{
	for (int i = 0; (*array)[i]; i++)
		free((*array)[i]);
	free(*array);
}

void free_labels(label_t ***labels)
{
	for (int i = 0; (*labels)[i]; i++) {
		free((*labels)[i]->name);
		for (int j = 0; (*labels)[i]->lines[j]; j++) {
			free((*labels)[i]->lines[j]);
		}
		free((*labels)[i]->lines);
		free_instructions((*labels)[i]->ins);
		free((*labels)[i]);
	}
	free(*labels);
}