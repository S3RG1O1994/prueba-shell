#include "shell.h"

/**
 * _strdup - Duplicate a string.
 * @str: String to duplicate.
 * Return: Allways char.
 */
char *_strdup(char *str)
{
	int a, i;
	char *copy_str = NULL;

	if (str == NULL)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
	{}
	copy_str = malloc(sizeof(char) * a + 1);
	if (copy_str == NULL)
		return (NULL);
	for (i = 0; i < a; i++)
		copy_str[i] = str[i];
	copy_str[i] = '\0';
	return (copy_str);
}
