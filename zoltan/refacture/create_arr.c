#include "shell.h"

/**
 * create_arr - function
 * @arguments: arguments
 *
 * Return: matrix
 */
char **create_arr(char *arguments)
{
	char *args = NULL, *tmp = NULL, **arr = NULL;
	int count = 0;

	args = _strdup(arguments);
	while (args[count] != '\n')
		count++;
	args[count] = '\0';
	arr = malloc(sizeof(char *) * 2);
	if (!arr)
	{
		free(args);
		return (0);
	}
	tmp = shortener(args);
	arr[0] = space_eliminator(tmp);
	arr[1] = NULL;
	free(tmp);
	free(args);
	return (arr);
}
