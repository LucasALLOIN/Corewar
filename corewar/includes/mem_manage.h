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

void int_to_uchar(int nb, byte_t *byte);
int uchar_to_int(byte_t *byte);
void short_to_uchar(short nb, byte_t *byte);
short uchar_to_short(byte_t *byte);

#endif /* MEM_MANAGE_H_ */
