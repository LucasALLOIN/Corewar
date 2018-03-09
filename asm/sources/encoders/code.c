/*
** EPITECH PROJECT, 2017
** sources/encoders/code.c
** File description:
**
*/

#include "asm.h"
#include "utils.h"

static label_t **first_pass(char const *code)
{
	label_t **labels = 0x0;
	int nb_labels = 0;
	GARBAGE_ARR char **lines = split_lines(code);

	preparse(lines);
	for (int i = 0; lines[i]; i++) {
		if (match(lines[i], "*:") && !match(lines[i], "*%:")) {
			nb_labels++;	
		}	
	}
	labels = my_calloc(sizeof(label_t*) * (nb_labels + 1));
	nb_labels = 0;
	for (int i = 0; lines[i];) {
		if (match(lines[i], "*:") && !match(lines[i], "*%:")) {
			labels[nb_labels] = my_calloc(sizeof(label_t));
			i += create_label(labels[nb_labels], lines + i);
			nb_labels++;
		}
	}
	return (labels);
}

static void second_pass(label_t **labels)
{
	for (int i = 0; labels[i]; i++) {
		if (i == 0) {
			labels[i]->id = 0;
		} else {
			labels[i]->id = labels[i - 1]->id + labels[i - 1]->sz;
		}
		labels[i]->sz = compute_label_size(labels[i]);
	}
}

static int third_pass(label_t **labels)
{
	label_t *temp = 0x0;
	char **lines = 0x0;
	int to_alloc = 0;
	int index = 0;

	for (int i = 0; labels[i]; i++) {
		temp = labels[i];
		lines = labels[i]->lines;
		for (int j = 0; lines[j]; j++, to_alloc++);
		temp->ins = my_calloc(sizeof(ins_t) * (to_alloc + 1));
		for (int j = 0; lines[j]; j++) {
			temp->ins[j] = line_encoding(lines[j], labels, index);
			index += compute_line_size(lines[j]);
		}
	}
	return (index);
}

static void fourth_pass(label_t **labels, int fd)
{
	for (int i = 0; labels[i]; i++) {
		for (int j = 0; labels[i]->ins[j]; j++) {
			encode_instruction(labels[i]->ins[j], fd);
		}
	}
}

int encode_code(char const *code, int fd, header_t *header)
{
	GARBAGE_LAB label_t **labels = first_pass(code);

	second_pass(labels);
	header->prog_size = third_pass(labels);
	encode_header(header, fd);
	fourth_pass(labels, fd);
	return (0);
}