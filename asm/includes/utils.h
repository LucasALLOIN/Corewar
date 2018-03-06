/*
** EPITECH PROJECT, 2017
** sources/utils/utils.h
** File description:
** Header file for utilities function
*/

#ifndef UTILS_H_
#define UTILS_H_

#include "asm.h"

#define READ_SIZE (1024)

void free_it(char **pointer);
void free_array(char ***array);
void free_labels(label_t ***labels);

#define GARBAGE __attribute__((cleanup(free_it)))
#define GARBAGE_ARR __attribute__((cleanup(free_array)))
#define GARBAGE_LAB __attribute__((cleanup(free_labels)))

union endianner {
	char c;
	short int si;
	int n;
	char s[4];
};

void *my_calloc(int size);
int my_strlen(char const *str);
char *get_next_line(int fd);
int match(char const *s1, char const *s2);
char *get_file(int fd);
char *my_strcat(char *src1, char *src2);
char *clean_str(char const *str);
char *append(char *src, char c);
int find_next(char const *mem, char c);
void my_memcpy(void *mem_dest, const void *mem_src, int len);
int find_prec(char const *mem, int index, char c);
char **split_lines(char const *str);
char **split_spaces(char const *str);
int my_atoi(char const *str);
int my_memcmp(void const *memblock1, void const *memblock2);
void err_write(char const *error, int line_n);
char *get_file_name(char *str);
int ignore_line(char const *line);
int find_non_ingored(int index, char **lines);

#endif /* UTILS_H_ */
