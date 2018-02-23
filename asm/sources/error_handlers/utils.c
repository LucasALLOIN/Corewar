/*
** EPITECH PROJECT, 2017
** sources/error_handlers/utils.c
** File description:
**
*/

static void putnbr_err(int n)
{

}

char *get_file_name(char *str)
{
	static char *database = 0x0;

	if (str) {
		database = str;
	} else {
		return (database);
	}
	return (0x0);
}

void err_write(char const *error, int line_n)
{
	write(2, "\033[1m", 4);
	write(2, "asm, ", 5);
	write(2, "test", 4);
	write(2, ", line ", 7);
	putnbr_err(line_n);
	write(2, ": \033[1;36m", 9);
	write(2, error, my_strlen(error));
	write(2, "\033[0m", 4);
}