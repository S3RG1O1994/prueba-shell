#include "shell.h"

/**
 * simple_arr - Create array with command and NULL.
 * @command: Command whit command.
 * @words: Numbers of arrays.
 *
 * Return: Always array.
 */
char **simple_arr(char *command, int words)
{
	char **arr;

	arr = malloc(sizeof(char *) * words);
		if (!arr)
			return (NULL);
		arr[0] = command;
		arr[1] = NULL;
	return (arr);
}
