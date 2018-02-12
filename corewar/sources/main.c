/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function of the corewar
*/

#include "utils.h"
#include "my_printf.h"
#include "corewar.h"

//TODO: add to the structure during the initialisation
int get_args(char *argv[], int i)
{
	switch (argv[i][1]) {
	case 'n':
		//live code = my_getnbr(argv[i + 1]);
	case 'a':
		//adress load = my_getnbr(argv[i + 1]);
	default:
		if (my_strcmp(argv[i], "-dump")) {
			//int nb_cycle = my_getnbr(argv[i + 1]);
		} else {
			my_printf("%s: No such argument\n", argv[i]);
			return (-1);
		}
	};
	return (0);
}

int parse_args(char *argv[])
{
	int i = 0;
	int nb_champ = 0;
	int err = 0;
	
	while (argc >= i && argv[i] != 0x0) {
		if (argv[i][0] == '-') {
			err = get_args(argv, i);
		} else if (i && argv[i - 1][0] != '-') {
			//add champion to the list
			nb_champ++;
		}
		if (err != 0)
			return (-1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	if (parse_args(argv) == -1) {
		my_printf("usage\n");
		return (84);
	}
	
	return (0);
}
