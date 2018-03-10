/*
** EPITECH PROJECT, 2017
** includes/asm.h
** File description:
** Assembler header
*/

#ifndef ASM_H_
#define ASM_H_

#include "op.h"

struct instruction {
	char code;
	int control_byte;
	int param1;
	int param2;
	int param3;
	int index;
};

typedef struct instruction ins_t;

struct label {
	char *name;
	int id;
	int sz;
	char **lines;
	ins_t **ins;
};

typedef struct label label_t;

int error_handler(char const *file);
void preparse(char ***lines);
int check_name(char **lines);
int check_comment(char **lines);
int check_labels(char **lines);
int check_instructions(char **lines);

char *split(char const *file, header_t *header, int *skipped_lines);
void encode_header(header_t *header, int fd);
int encode_code(char const *code, int fd, header_t *header);
int assembler(int ac, char **av);
int detect_comment(int fd, char **desc);
int detect_name(int fd, char **name);
int check_coding_byte(char **params, int index_ins);
int compute_line_size(char const *line);
ins_t *line_encoding(char const *line, label_t **labels, int index);
int create_label(label_t *label, char **lines);
int compute_label_size(label_t *label);
int compute_line_size(char const *line);
void encode_instruction(ins_t *op, int fd);
int has_not_coding_byte(char const *line);
char *clean_separator(char *str);
int file_error_handler(char const *file);
void free_instructions(ins_t **ins);

#endif /* ASM_H_ */
