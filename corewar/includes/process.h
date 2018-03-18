/*
** EPITECH PROJECT, 2018
** prog.h
** File description:
** program header struct
*/

#ifndef PROG_H_
#define PROG_H_

typedef struct process_s {
	byte_t registers[REG_NUMBER][REG_SIZE];
	int load_adress;
	int turn_to_exec;
	int was_waiting;
	unsigned int pc;
	int carry;
	int id;
	struct program_s *parent;
	struct process_s *next;
} process_t;

#endif /* PROG_H_ */
