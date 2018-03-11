/*
** EPITECH PROJECT, 2017
** includes/op.h
** File description:
** header for predefined constants and structs
*/

#ifndef _OP_H_
#define _OP_H_

static const char COMMENT_CHAR = '#';
static const char LABEL_CHAR = ':';
static const char SEPARATOR_CHAR = 44;

static const int REG_NUMBER = 16;

static const int MAX_ARGS_NUMBER = 4;

typedef char args_type_t;

static const int T_REG = 1;
static const int T_DIR = 2;
static const int T_IND = 4;
static const int T_LAB = 8;

struct op {
	char *mnemonique;
	char nbr_args;
	args_type_t type[4];
	char code;
	int nbr_cycles;
	char *comment;
};

typedef struct op op_t;

static const int IND_SIZE = 2;
static const int DIR_SIZE = 4;
static const int REG_SIZE = 4;

static const int PROG_NAME_LENGTH = 128;
static const int COMMENT_LENGTH = 2048;
static const int COREWAR_EXEC_MAGIC = 0xea83f3;

struct header {
	int magic;
	char *prog_name;
	int prog_size;
	char *comment;
};

typedef struct header header_t;

#endif
