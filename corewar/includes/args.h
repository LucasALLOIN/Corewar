/*
** EPITECH PROJECT, 2018
** args.h
** File description:
** args functions
*/

#ifndef ARGS_H_
#define ARGS_H_

typedef struct program_s {
	int live_code;
	int adress;
	char *file_name;
	struct program_s *next;
} program_l;

#endif /* ARGS_H_ */
