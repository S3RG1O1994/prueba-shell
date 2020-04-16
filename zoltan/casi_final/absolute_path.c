#include "shell.h"

/**
 * absolute_path - Create an array with absolute path.
 * @args: Contains the arguments.
 *
 * Return: Allways array to execve.
 */
char **absolute_path(char *args)
{
	char **arr = NULL, *ar_d = NULL, *command = NULL;
	int count = 0, count_2 = 0, rreturn_stat;

	while (args[count] != ' ' && args[count] != '\n')
		count++;
	command = malloc(sizeof(char) * count + 1);
	if (!command)
		return (NULL);
	ar_d = _strdup(args);

	while (count_2 < count)
	{
		command[count_2] = ar_d[count_2];
		count_2++;
	}
	command[count_2] = '\0';

	free(ar_d);
	count = 0;
	rreturn_stat = stat_func(command);
	if (rreturn_stat == 0)
	{
		arr = add_arr(args, command);
		if (!arr)
			return (NULL);
		return (arr);
	}
	free(command);
	return (arr);
}
