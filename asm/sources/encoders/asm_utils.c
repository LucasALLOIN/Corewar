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

int has_not_coding_byte(char const *line)
{
	int s_i = find_next(line, ' ');

	return (my_memncmp(line, "live", s_i) ||
		my_memncmp(line, "zjmp", s_i) ||
		my_memncmp(line, "fork", s_i) ||
		my_memncmp(line, "lfork", s_i));
}

int write_endian(char *mem, int param, int n_bytes)
{
	int written = n_bytes;
	union endianner endian;

	switch (n_bytes) {
	case 1:
		endian.c = param;
		break;
	case 2:
		endian.si = param;
		break;
	case 4:
		endian.n = param;
	}
	for (char *temp = mem; n_bytes; n_bytes--, temp++) {
		*temp = endian.s[n_bytes - 1];
	}
	return (written);
}

int write_param(char *str, int param, int param_n, ins_t *op)
{
	int local_control = (op->control_byte >> (8 - (param_n * 2))) & 3;
	int direct_n = op->code == 10 || op->code == 11 || op->code == 14;
	
	switch (local_control) {
	case 0b01:
		return (write_endian(str, param, 1));
	case 0b10:
		return (write_endian(str, param, direct_n ? 2 : 4));
	case 0b11:
		return (write_endian(str, param, 2));
	default:
		return (0);
	}
}

int compute_instruction_size(ins_t *op)
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

void encode_instruction(ins_t *op, int fd)
{
	int i = 0;
	GARBAGE char *mem = my_calloc(compute_instruction_size(op) + 1);

	mem[i++] = op->code;
	if (op->code == 0x01 || op->code == 0x09 ||
		op->code == 0x0c || op->code == 0x0f) {
		if (op->code == 0x01) {
			i += write_endian(mem + i, op->param1, 4);
		} else {
			i += write_endian(mem + i, op->param1, 2);
		}
	} else {
		mem[i++] = (char) op->control_byte & 255;
		i += write_param(mem + i, op->param1, 1, op);
		i += write_param(mem + i, op->param2, 2, op);
		i += write_param(mem + i, op->param3, 3, op);
	}
	write(fd, mem, i);
}