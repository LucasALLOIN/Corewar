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

void int_to_uchar(int nb, byte_t *byte);
int uchar_to_int(byte_t *byte);

#endif /* MEM_MANAGE_H_ */
