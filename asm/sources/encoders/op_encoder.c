/*
** EPITECH PROJECT, 2017
** sources/encoders/op_encoder.c
** File description:
**
*/

#include "asm.h"
#include "op.h"
#include "utils.h"

int check_coding_byte(char **params, int op_code)
{
	int params_n = 0;
	int control = 0;

	for (int i = 0; params[i]; i++, params_n++) {
		control = control << 2;
		if (params[i][0] == 'r') {
			control += 1;
		} else if (params[i][0] == '%' && params[i][1] != ':') {
			control += 2;
		} else {
			control += 3;
		}
	}
	control = control << 2 * (4 - params_n);
	return (control);
}

int get_label(char *param, label_t **labels, instruction_t *op)
{
	for (int i = 0; labels[i]; i++) {
		if (match(param, labels[i]->name)) {
			return (labels[i]->id - op->index);
		}
	}
	return (0);
}

/*
** Check params here
*/
int parse(instruction_t *op, int control, char *param, label_t **labels)
{
	if (param == 0x0 || control == 0)
		return (0);
	if (control == 0b11	 && param[1] == ':') {
		return (get_label(param, labels, op));
	} else {
		if (control == 0b11)
			return (my_atoi(param));
		else
			return (my_atoi(param + 1));
	}
}

void parse_param(instruction_t *op, char **params, int n, label_t **labels)
{
	int local_control = (op->control_byte >> (8 - (2 * n))) & 3;
	int parsed_param = 0;
	char *param = local_control ? params[n - 1] : 0x0;

	parsed_param = parse(op, local_control, param, labels);
	if (n == 1)
		op->param1 = parsed_param;
	else if (n == 2)
		op->param2 = parsed_param;
	else
		op->param3 = parsed_param;
}

instruction_t *line_encoding(char const *line, label_t **labels, int index)
{
	char **params = split_spaces(line);
	instruction_t *op = my_calloc(sizeof(instruction_t));

	op->code = 0;
	for (int i = 0; i < 16 && !op->code; i++) {
		if (match(params[0], op_tab[i].mnemonique)) {
			op->code = op_tab[i].code;
		}
	}
	op->index = index;
	op->control_byte = check_coding_byte(params + 1, op->code) & 255;
	parse_param(op, params + 1, 1, labels);
	parse_param(op, params + 1, 2, labels);
	parse_param(op, params + 1, 3, labels);
	return (op);
}