/*
** op.h for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Tue Mar 22 16:44:20 2011 Astek
*/

#ifndef _OP_H_
#define _OP_H_

#define COMMENT_CHAR '#'
#define REG_CHAR 'r'
#define LABEL_CHAR ':'
#define DIRECT_CHAR '%'
#define SEPARATOR_CHAR ','

#define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING ".name"
#define COMMENT_CMD_STRING ".comment"

#define REG_NUMBER (16)

#define MAX_ARGS_NUMBER (4)

typedef char args_type_t;

#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8

struct op {
        char *mnemonique;
        char nbr_args;
        args_type_t type[MAX_ARGS_NUMBER];
        char code;
        int nbr_cycles;
        char *comment;
};

typedef struct op op_t;

#define IND_SIZE 2
#define DIR_SIZE 4
#define REG_SIZE DIR_SIZE

#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 2048
#define COREWAR_EXEC_MAGIC 0xea83f3

struct header {
   int  magic;
   char *prog_name;
   int  prog_size;
   char *comment;
};

typedef struct header header_t;

#endif
