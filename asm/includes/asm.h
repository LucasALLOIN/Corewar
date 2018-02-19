/*
** EPITECH PROJECT, 2017
** includes/asm.h
** File description:
** Assembler header
*/

#ifndef ASM_H_
#define ASM_H_

struct program {
	char *name;
	char *description;
	char *code;
};

typedef struct program program_t;

program_t *split(char const *file);
void free_program(program_t *program);
int encode_name(char const *name, int fd);
int encode_description(char const *description, int fd);
int assembler(int ac, char **av);
int detect_comment(int fd, char **desc);
int detect_name(int fd, char **name);

#endif /* ASM_H_ */