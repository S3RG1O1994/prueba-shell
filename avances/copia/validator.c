#include "shell.h"

int sp_tab_finder(char *str)
{
	int count = 0;

	while (str[count] != '\n' && (str[count] == '\t' || str[count] == ' '))
		count++;

	if (str[count] == '\n')
		return (1);
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

char *shortener(char *string)
{
	int count, count_2 = 0, count_aux, size = 0;
	char *dup = NULL;

	for (count = 0; string[count] != '\n' && (string[count] == '\t' || string[count] == ' '); count++)
	{
	}
	printf("antes del primer  while\n");
	count_aux = count;
	while (string[count_aux])
	{
		size++;
		count_aux++;
	}
	dup = malloc(sizeof(char) * size + 1);
	printf("antes del segundo while\n");
	while (string[count])
	{
		dup[count_2] = string[count];
		count_2++;
		count++;
	}
	dup[count_2] = '\0';
	printf("Despues del segundo while\n");
	if (!dup)
		return (NULL);

	return (dup);
}
