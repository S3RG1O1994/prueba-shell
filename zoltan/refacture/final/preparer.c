#include "shell.h"

/**
 * shortener - Function of delete space an begenning array.
 * @string: Pointer an string of commands.
 * Return: Duplicate string without space.
 */
char *shortener(char *string)
{
	int count, count_2 = 0, count_aux, size = 0;
	char *dup = NULL;

	for (count = 0; string[count] != '\n' && (string[count] == '\t' ||
						string[count] == ' ');
	count++)
	{
	}
	count_aux = count;
	while (string[count_aux])
	{
		size++;
		count_aux++;
	}
	dup = malloc(sizeof(char) * size);
	if (!dup)
		return (NULL);
	while (string[count] != '\n')
	{
		dup[count_2] = string[count];
		count_2++;
		count++;
	}
	dup[count_2] = '\0';
	return (dup);
}

/**
 * space_eliminator -  Function of delete space an finally array.
 * @string: Pointer an string of commands.
 * Return: Duplicate string without space.
 */
char *space_eliminator(char *string)
{
	int count = 0, count2 = 0, space_count = 0;
	char *dup;

	while (string[count] != '\0')
	{
		if (string[count] == ' ' || string[count] == '\t')
			space_count++;
		else
			space_count = 0;
		count++;
	}

	dup = malloc(sizeof(char) * count - space_count + 1);
	if (!dup)
		return (NULL);
	while (count2 < count - space_count)
	{
		dup[count2] = string[count2];
		count2++;
	}
	dup[count2] = '\0';
	return (dup);
}

/**
 * preparer - Function that call other functions for quit spaces.
 * @args: Pointer an string of commands.
 * Return: Duplicate string without space.
 */
char *preparer(char *args)
{
	char *tmp = NULL, *aux = NULL;

	tmp = shortener(args);
	aux = space_eliminator(tmp);
	free(tmp);
	return (aux);
}
