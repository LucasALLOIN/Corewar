/*
** EPITECH PROJECT, 2017
** sources/error_handlers/preparser.c
** File description:
** preparer.c
*/

static char *clean_separators(char *line)
{	
	char *temp = 0x0;

	for (int i = 0; line[i]; i++) {
		if (line[i] == ',')
			line[i] = ' ';
	}
	temp = clean_str(line);
	free(line);
	return (temp);
}

void preparse(char **lines)
{
	for (int i = 0; lines[i]; i++) {
		lines[i] = clean_separators(lines[i]);
	}
}