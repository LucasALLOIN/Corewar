/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function of the corewar
*/

#include "utils.h"
#include "my_printf.h"
#include "corewar.h"
#include "bin_parser.h"

int get_args(char *argv[], int i, core_t *core, int nb_champ)
{
	switch (argv[i][1]) {
	case 'n':
		core->program_tab[nb_champ].live_code = my_getnbr(argv[i + 1]);
		break;
	case 'a':
		core->program_tab[nb_champ].adress = my_getnbr(argv[i + 1]);
		core->program_tab[nb_champ].process_l->load_adress = \
			my_getnbr(argv[i + 1]);
		break;
	default:
		if (my_strcmp(argv[i], "-dump")) {
			core->nb_dump = my_getnbr(argv[i + 1]);
			my_printf("dump = %s\n", argv[i + 1]);
		} else {
			my_printf("%s: No such argument\n", argv[i]);
			my_printf("%s\n", argv[i]);
			return (-1);
		}
	};
	return (0);
}

int parse_args(int argc, char *argv[], core_t *corewar)
{
	int i = -1;
	int nb_champ = 0;
	int err = 0;

	while (argc >= ++i && argv[i] != 0x0) {
		if (argv[i][0] == '-' && argc > i)
			err = get_args(argv, i, corewar, nb_champ);
		else if (i && argv[i - 1][0] != '-') {
			corewar->program_tab[nb_champ].file_name = \
				my_calloc(my_strlen(argv[i]) + 1);
			my_strcpy(corewar->program_tab[nb_champ].file_name, \
					argv[i]);
			nb_champ++;
		}
		if (err != 0)
			return (-1);
	}
	corewar->nb_progs = nb_champ;
	return (0);
}

int is_champ_alive(core_t *core)
{
	int z = 0;

	for (int i = 0; i < core->nb_progs; i++) {
		if (core->program_tab[i].is_alive)
			z++;
	}
	if (z > 1)
		return (1);
	for (int i = 0; i < core->nb_progs; i++)
		if (core->program_tab[i].is_alive) {
			z = 3;
			my_printf("The player %d(%s) has won."
				, core->program_tab[i].number
				, core->program_tab[i].header.prog_name);
		}
	return (0);
}

int main(int argc, char *argv[])
{
	core_t *corewar = create_core();
	int err = 0;

	if (parse_args(argc, argv, corewar) == -1) {
		my_printf("usage\n");
		return (84);
	}
	for (int i = 0; i < corewar->nb_progs; i++)
		err = bin_parser(corewar, i);
	if (err == -1)
		return (84);
	corewar_init(corewar);
	while (is_champ_alive(corewar))
		cycle(corewar);
	return (0);
}
