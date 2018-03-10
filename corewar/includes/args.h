/*
** EPITECH PROJECT, 2018
** args.h
** File description:
** args functions
*/

#ifndef ARGS_H_
#define ARGS_H_

/*
** program_t: program information structure
**
** live_code: vm_number
** adress: starting adress
** filename: PATH to the file
*/
typedef struct program_s {
	int live_code;
	int adress;
	char *file_name;
	process_t *process_l;
	int is_alive;
	int number;
	int fd;
	int last_live_cycle;
	header_t header;
} program_t;

#endif /* ARGS_H_ */
