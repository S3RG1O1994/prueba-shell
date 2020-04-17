#include "shell.h"

/**
 * create_arr - function
 * @arguments: arguments
 * @av: the pointer char
 * @counter: the int
 *
 * Return: matrix
 */
char **create_arr(char *arguments, char *av, int counter)
{
	char **arr = NULL;
	char *real_path = _getenv("PATH", environ), *copy_path = NULL;
	char *path = NULL, *vector = NULL;
	int rreturn_stat = 0, count = 0, count_2 = 0;

	copy_path = _strdup(real_path);
	if (arguments[0] == '/')
	{
		arr = absolute_path(arguments, av, counter);
		if (!arr)
			return (free(arguments),  NULL);
		while (arr[count_2])
			count_2++;
		arr[count_2 + 1] = copy_path;
		return (arr);
	}
	path = copy_path;
	path = strtok(path, ":");

	while (path)
	{
		vector = concatenate(arguments, path);
		rreturn_stat = stat_func(vector);
		if (rreturn_stat == 0)
		{
			arr = add_arr(arguments, vector);
			while (arr[count])
				count++;
			arr[count + 1] = copy_path;
			return (arr);
		}
		path = strtok(NULL, ":");
		free(vector);
	}
	print_error(av, counter, arguments);
	return (free(copy_path), NULL);
}
