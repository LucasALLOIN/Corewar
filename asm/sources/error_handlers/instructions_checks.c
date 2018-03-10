/*
** EPITECH PROJECT, 2017
** sources/error_handlers/instructions_checks.c
** File description:
**
*/

#include "op.h"
#include "utils.h"

static const op_t op_tab[] = {
    	{"live", 1, {T_DIR}, 1, 10, "alive"},
    	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6,
	6, "et (and  r1, r2, r3   r1&r2 -> r3"},
    	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     	"ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8,
	6, "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     	"load index"},
    	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     	"store index"},
    	{"fork", 1, {T_DIR}, 12, 800, "fork"},
    	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
	"long load index"},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
	{"aff", 1, {T_REG}, 16, 2, "aff"},
	{0x0, 0, {0}, 0, 0, 0x0}
};

static int check_arg(char const *arg, char arg_type)
{
	if (arg_type & T_IND) {
		if ((arg[0] <= '9' && arg[0] >= '0') || arg[0] == '-')
			return (0);
	}
	if (arg_type & T_REG) {
		if (arg[0] == 'r')
			return (0);
	}
	if (arg_type & T_DIR) {
		if (arg[0] == '%')
			return (0);
	}
	return (84);
}

static int check_args_for(char **lines, int inst, int n_line)
{
	GARBAGE_ARR char **params = split_spaces(lines[n_line]);
	int args = 0;
	int code = 0;

	for (int i = 1; !code && params[i] && params[i][0] != '#'; i++) {
		code = check_arg(params[i], op_tab[inst].type[i - 1]);
		args++;
	}
	if (code || args < op_tab[inst].nbr_args) {
		err_write("The argument given"
		" to the instruction is invalid.\n", n_line + 1);
		return (84);
	}
	return (0);
}

static int check_inst_name(char **line, int *instruction, int n_line)
{
	int last_space = find_next(line[n_line], ' ');
	char *inst = my_calloc(last_space + 1);

	my_memcpy(inst, line[n_line], last_space);
	for (int i = 0; op_tab[i].mnemonique; i++) {
		if (my_memcmp(op_tab[i].mnemonique, inst)) {
			*instruction = i;
			return (0);
		}
	}
	err_write("Invalid instruction.\n", n_line + 1);
	return (84);
}

static int check_args(char **lines, int inst, int n_line)
{
	GARBAGE_ARR char **params = split_spaces(lines[n_line]);
	int reg = 1;
	int code = 0;

	for (int i = 1; !code && params[i] && params[i][0] != '#'; i++) {
		if (i > op_tab[inst].nbr_args) {
			err_write("Too many arguments"
			" given to the instruction.\n", n_line + 1);
			return (84);
		}
		if (params[i][0] == 'r') {
			reg = my_atoi(params[i] + 1);
		}
		if (reg > REG_NUMBER || reg < 1) {
			err_write("Invalid register number.\n", n_line + 1);
			return (84);
		}
	}
	return (0);
}

int check_instructions(char **lines)
{
	int first_inst = find_non_ingored(0, lines);
	int ret = 0;
	int current_inst = 16;

	first_inst = find_non_ingored(first_inst, lines);
	first_inst = find_non_ingored(first_inst, lines);
	for (int i = first_inst; !ret && i != -1 && lines[i];) {
		if (match(lines[i], "*:") && !match(lines[i], "*%:*")) {
			i = find_non_ingored(i, lines);
			continue;
		}
		ret = ret ? ret : check_inst_name(lines, &current_inst, i);
		ret = ret ? ret : check_args(lines, current_inst, i);
		ret = ret ? ret : check_args_for(lines, current_inst, i);
		i = find_non_ingored(i, lines);
	}
	return (ret);
}