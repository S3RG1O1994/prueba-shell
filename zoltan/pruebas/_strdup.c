#include "shell.h"

/**
 * _strdup - Duplicate a string.
 * @str: String to duplicate.
 * Return: Allways char.
 */
char *_strdup(char *str)
{
	char *ptr;
	int c, i;

	if (str == NULL)
		return (NULL);
	for (c = 0; str[c] != '\0'; c++)
	{
	}

	ptr = malloc(c + 1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < c; i++)
		ptr[i] = str[i];

	return (ptr);
}
