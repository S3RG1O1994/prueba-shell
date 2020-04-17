#include "shell.h"

/**
 * sp_tab_finder - despcription
 * @str: str
 *
 * Return: 0
 */
int sp_tab_finder(char *str)
{
	int count = 0;

	while (str[count] != '\n' && (str[count] == '\t' || str[count] == ' '))
		count++;

	if (str[count] == '\n')
		return (1);
	return (0);
}

/**
 * validator - despcription
 * @string: str
 *
 * Return: 0
 */
int validator(char *string)
{
	int val;

	val = sp_tab_finder(string);
	if (val == 1)
		return (1);
	else
		return (0);
}
