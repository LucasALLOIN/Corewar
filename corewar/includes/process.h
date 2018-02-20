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
	header_t header;
	int turn_to_exec;
	int was_waiting;
	unsigned int pc;
	int carry;
	int is_alive;
	int last_live_cycle;
	int fd;
	int number;
	struct process_s *next;
} process_t;

#endif /* PROG_H_ */
