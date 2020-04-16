#include "shell.h"

/**
 * space_eliminator - function
 * @string: arguments
 *
 * Return: argument
 */
char *space_eliminator(char *string)
{
	int count, count2;
	char *dup;

	for (count = 1; string[count] != ' ' && string[count] != '\t' &&
		     string[count] != '\0'; count++)
	{
	}
	dup = malloc(sizeof(char) * count + 1);
	if (!dup)
		return (NULL);
	for (count2 = 0; count2 < count; count2++)
		dup[count2] = string[count2];
	dup[count2] = '\0';
	return (dup);
}
