#include "shell.h"

/**
 * add_arr - Create an array with command and possible arguments.
 * @str: Command and arguments.
 * @command: Path and command.
 *
 * Return: Allways array.
 */
char **add_arr(char *str, char *command)
{
	int count = 0, space = 0, count_2 = 0, words = 4;
	char *copy = NULL, **arr = NULL;

	while (str[count])
	{
		if (str[count] == ' ')
			space++;
		count++;
	}
	if (space == 0)
	{
		arr = simple_arr(command, (words - 1));
		return (arr);
	}

	count = 0;
	while (str[count_2] != ' ' && str[count_2] != '\n')
		count_2++;
	copy = _strdup(&str[count_2 + 1]);
	while (copy[count])
	{
		if (copy[count] == ' ')
			words++;
		count++;
	}
	arr = malloc(sizeof(char *) * words);
	if (!arr)
		return (NULL);
	arr[0] = command;
	count = 1;
	copy = strtok(copy, "\n ");
	while (count < words)
	{
		arr[count] = copy;
		copy = strtok(NULL, " ");
		count++;
	}
	return (arr);
}
