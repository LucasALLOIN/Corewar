/*
** EPITECH PROJECT, 2017
** instruction.c
** File description:
** instructions utils functions
*/

#include "corewar.h"

/*
** check_valid: 
** check if the args is valide for the actual instructions.
**
** int *args: args given to the instructions.
** int one, two, th : args that the instructions need.
*/
int check_valid(int *args, int one, int two, int th)
{
	return ((args[0] & one && args[1] & two && args[2] & th) ? 1 : 0);
}

