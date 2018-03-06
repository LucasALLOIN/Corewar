/*
** EPITECH PROJECT, 2018
** mem_manage.h
** File description:
** program header struct
*/

#ifndef MEM_MANAGE_H_
#define MEM_MANAGE_H_

typedef union mem_int_s {
	int nb;
	byte_t byte[4];
} mem_int_t;

typedef union mem_short_s {
	short nb;
	byte_t byte[2];
} mem_short_t;

void int_to_uchar(core_t *core, process_t *process, int nb, int start);
int uchar_to_int(core_t *core, int start);
void short_to_uchar(core_t *core, process_t *process, short nb, int start);
short uchar_to_short(core_t *core, int start);

int liget_mem(process_t *process, core_t *core, int type, int *last);
int iget_mem(process_t *process, core_t *core, int type, int *last);
int lget_mem(process_t *process, core_t *core, int type, int *last);
int get_mem(process_t *process, core_t *core, int type, int *last);

void int_to_reg(int nb, byte_t *byte);
int reg_to_int(byte_t *byte);
void short_to_reg(short nb, byte_t *byte);
short reg_to_short(byte_t *byte);
#endif /* MEM_MANAGE_H_ */
