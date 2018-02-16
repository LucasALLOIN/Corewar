/*
** EPITECH PROJECT, 2018
** prog.h
** File description:
** program header struct
*/

#ifndef PROG_H_
#define PROG_H_

typedef struct prog_s {
	byte_t registers[REG_NUMBER][REG_SIZE];
	int load_adress;
	header_t header;
	int turn_to_exec;
	int pc;
	int fd;
	int number;
} process_t;

#endif /* PROG_H_ */
