/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** str len
*/

static int if_part_2(const char *copy, const char *str)
{
	if (copy[4] == 0)
		return (copy - str + 4);
	else if (copy[5] == 0)
		return (copy - str + 5);
	else if (copy[6] == 0)
		return (copy - str + 6);
	else
		return (copy - str + 7);
}

static int if_part_1(const char *copy, const char *str)
{
	if (copy[0] == 0)
		return (copy - str);
	else if (copy[1] == 0)
		return (copy - str + 1);
	else if (copy[2] == 0)
		return (copy - str + 2);
	else if (copy[3] == 0)
		return (copy - str + 3);
	return (if_part_2(copy, str));
}

int my_strlen(const char *str)
{
	const char *char_ptr = str;
	unsigned long int high_bit = 0x8080808080808080L;
	unsigned long int low_bit = 0x0101010101010101L;
	unsigned long int long_word;
	const unsigned long int *long_word_ptr;
	const char *copy;

	while ((((unsigned long int) ++char_ptr) &
		sizeof(long_word) - 1) != 0)
		if (*char_ptr == '\0')
			return (char_ptr - str);
	long_word_ptr = (unsigned long int *) char_ptr;
	while (1) {
		long_word = *long_word_ptr++;
		if (((long_word - low_bit) & high_bit) != 0) {
			copy = (const char *) (long_word_ptr - 1);
			return (if_part_1(copy, str));
		}
	}
}
