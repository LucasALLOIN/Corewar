/*
** EPITECH PROJECT, 2017
** match
** File description:
** Function that returns wheter or not the s2 string matches the s1 string
*/

static int match_nc(char const *str1, char const *str2, int ctr1, int ctr2);

static int match_do(char const *str1, char const *str2, int ctr1, int ctr2)
{
	if (str1[ctr1] == str2[ctr2] && str1[ctr1])
		return (match_nc(str1, str2, ctr1 + 1, ctr2 + 1));
	else if (str1[ctr1] == str2[ctr2] && !(str1[ctr1]))
		return (1);
	return (0);
}

static int match_nc(char const *str1, char const *str2, int ctr1, int ctr2)
{
	if (str2[ctr2] == '*' && str1[ctr1])
		return (match_nc(str1, str2, ctr1, ctr2 + 1));
	else if (str1[ctr1] != str2[ctr2] && str1[ctr1])
		return (match_nc(str1, str2, ctr1 + 1, ctr2));
	return (match_do(str1, str2, ctr1, ctr2));
}

int match(char const *s1, char const *s2)
{
	return (match_nc(s1, s2, 0, 0));
}
