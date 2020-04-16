#include "shell.h"

int sp_tab_finder(char *string)
{
	int count;

	for (count = 0; string[count] != '\n' && (string[count] == '\t' || string[count] == ' '); count++)
	{
	}
	if (string[count] == '\n')
	return (1);
	else
		return (0);
}

int point_finder(char *string)
{
	int count, pointcount = 0, val;

	for (count = 0; string[count] != '\n' && (string[count] == '\t' || string[count] == ' ' || string[count] == '.'); count++)
	{
		if (string[count] == '.')
			pointcount++;
	}
	if (pointcount == 1 && string[count] == '\n')
		return (1);
	else
		val = sp_tab_finder(string);
	return (val);
}

int validator(char *string)
{
	int val;

	val = point_finder(string);
	if (val == 1)
		return (1);
	else
		return (0);
}
