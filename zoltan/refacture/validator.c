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


/**
 * point_finder - despcription
 * @string: str
 *
 * Return: 0
 *
int point_finder(char *string)
{
	int count, pointcount = 0, val;

	for (count = 0; string[count] != '\n' && (string[count] == '\t' ||
						  string[count] == ' ' ||
						  string[count] == '.');
	     count++)
	{
		if (string[count] == '.')
			pointcount++;
	}
	if (pointcount == 1 && string[count] == '\n')
		return (1);
	val = sp_tab_finder(string);
	return (val);
	}*/
