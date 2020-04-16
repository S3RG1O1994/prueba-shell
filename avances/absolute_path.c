#include "shell.h"

/**
 * absolute_path - Create an array with absolute path.
 * @args: Contains the arguments.
 * @av: contains the first argument.
 * @counter: General counter.
 *
 * Return: Allways array to execve.
 */
char **absolute_path(char *args, char *av, int counter)
{
	char **arr = NULL,  /**ar_d = NULL,*/ *command = NULL;
	int count = 0, count_2 = 0, rreturn_stat;

	while (args[count] != ' ' && args[count] != '\n')
		count++;
	command = malloc(sizeof(char) * count + 1);
	if (!command)
		return (NULL);

	while (count_2 < count)
	{
		command[count_2] = args[count_2];
		count_2++;
	}
	command[count_2] = '\0';

	rreturn_stat = stat_func(command);
	if (rreturn_stat == 0)
	{
		arr = add_arr(args, command);
		return (arr);
	}
	free(command);
	print_error(av, counter, args);
	return (NULL);
}
