/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** Header for worewar ops.
*/

#ifndef _OP_H_
#define _OP_H_

static const int MEM_SIZE = (6*1024);
static const int IDX_MOD = 512;
static const int MAX_ARGS_NUMBER = 4;

static const int COMMENT_CHAR = '#';
static const int LABEL_CHAR = ':';
static const int DIRECT_CHAR = '%';
static const int SEPARATOR_CHAR = ',';

static const int REG_NUMBER = 16;

typedef char args_type_t;

static const int T_REG = 1;
static const int T_DIR = 2;
static const int T_IND = 4;
static const int T_LAB = 8;

struct  op_s {
	char *mnemonique;
	char nbr_args;
	args_type_t type[4];
	char code;
	int nbr_cycles;
	char *comment;
};

typedef struct op_s op_t;

static const int IND_SIZE = 2;
static const int DIR_SIZE = 4;
static const int REG_SIZE = 4;

extern op_t op_tab[];

static const int PROG_NAME_LENGTH = 128;
static const int COMMENT_LENGTH = 2048;
static const int COREWAR_EXEC_MAGIC = 0xea83f3;


struct header_s {
	int magic;
	char prog_name[129];
	int prog_size;
	char comment[2049];
};

typedef struct header_s header_t;

static const int CYCLE_TO_DIE = 1536;
static const int CYCLE_DELTA = 5;
static const int NBR_LIVE = 40;

#endif
