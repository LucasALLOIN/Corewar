/*
** EPITECH PROJECT, 2017
** sources/encoders/asm_utils.c
** File description:
**
*/

#include <unistd.h>
#include "asm.h"
#include "utils.h"
#include "op.h"

int create_label(label_t *label, char **lines)
{
	int max_lines = 0;
	int label_lines = 0;

	label->name = my_calloc(my_strlen(lines[0]));
	my_memcpy(label->name, lines[0], my_strlen(lines[0]) - 1);
	for (int i = 0; lines[i]; i++, max_lines++) {
		if (!label_lines && match(lines[i], "*:") && !match(lines[i], "*%:"))
			label_lines = i;
	}
	label_lines = label_lines ? label_lines : max_lines;
	label->lines = my_calloc(sizeof(char*) * (label_lines + 1));
	for (int i = 1; i < label_lines; i++) {
		label->lines[i - 1] = my_calloc(my_strlen(lines[i]) + 1);
		my_memcpy(label->lines[i - 1], lines[i], my_strlen(lines[i]));
	}
	return (label_lines);
}

static int has_not_coding_byte(char const *line)
{
	return (match(line, "live*") ||
		match(line, "zjmp*") ||
		match(line, "fork*") ||
		match(line, "lfork*"));
}


int compute_line_size(char const *line)
{
	int size = has_not_coding_byte(line) ? 1 : 2;
	char **params = split_spaces(line);

	for (int i = 1; params[i]; i++) {
		switch (params[i][0]) {
		case 'r':
			size += 1;
			break;
		case '%':
			size += params[i][1] == ':' ? IND_SIZE : DIR_SIZE;
			break;
		default:
			size += IND_SIZE;
		}
	}
	return (size);
}

int compute_label_size(label_t *label)
{
	int size = 0;

	for (int i = 0; label->lines[i]; i++) {
		size += compute_line_size(label->lines[i]);	
	}
	return (size);
}

int write_endian(char *mem, int param, int n_bytes)
{
	int written = n_bytes;

	for (char *temp = mem; n_bytes; n_bytes--, temp++) {
		if (n_bytes > 1)
			*temp = 0;
		else
			*temp = param;
	}
	return (written);
}

int write_param(char *str, int param, int param_n, int control)
{
	int local_control = (control >> (8 - (param_n * 2))) & 3;
	
	switch (local_control) {
	case 0b01:
		return write_endian(str, param, 1);
	case 0b10:
		return write_endian(str, param, 4);
	case 0b11:
		return write_endian(str, param, 2);
	default:
		return (0);
	}
}

int compute_instruction_size(instruction_t *op)
{
	int size = 1;

	if (op->code != 0x01 && op->code != 0x09 &&
		op->code != 0x0c && op->code != 0x0f)
		size++;
	for (int i = op->control_byte; i; i = i >> 2) {
		switch (i & 0b11) {
		case 1:
			size += 1;
			break;
		case 2:
			size += DIR_SIZE;
			break;
		case 3:
			size += IND_SIZE;
			break;
		}
	}
	return (size);
}

void encode_instruction(instruction_t *op, int fd)
{
	int i = 0;
	GARBAGE char *mem = my_calloc(compute_instruction_size(op) + 1);

	mem[i++] = op->code;
	if (op->code != 0x01 && op->code != 0x09 &&
		op->code != 0x0c && op->code != 0x0f) {
		mem[i++] = (char) op->control_byte & 255;
		if (op->code == 0x01) {
			i += write_endian(mem + i, op->param1, 4);
		} else {
			i += write_endian(mem + i, op->param1, 2);
		}
	} else {
		i += write_param(mem + i, op->param1, 1, op->control_byte);
		i += write_param(mem + i, op->param2, 2, op->control_byte);
		i += write_param(mem + i, op->param3, 3, op->control_byte);
	}
	write(fd, mem, i);
}