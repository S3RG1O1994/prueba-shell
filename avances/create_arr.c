#include "shell.h"

/**
 * create_arr - Create an array with executable path and possible arguments.
 * @arguments: Contains the commands.
 * @env: Contains the environment.
 * @av: contains the first argument.
 * @counter: General counter.
 *
 * Return: Allways matrix or NULL.
 */
char **create_arr(char *arguments, char **env, char *av, int counter)
{
	char *real_path = _getenv("PATH", env), *copy_path = NULL;
	char *path = NULL, *vector = NULL, **arr = NULL, *args = NULL;
	int rreturn_stat, count = 0, count_2 = 0, validator;

	args = shortener(arguments);
	validator = _merge(args, env);
	if (validator == 0)
		return (free(args), NULL);
	if (args[0] == '/')
	{
		arr = absolute_path(args, av, counter);
		if (!arr)
			return (free(args), free(copy_path), NULL);
		while (arr[count_2])
			count_2++;
		arr[count_2 + 1] = copy_path;
		return (free(args), arr);
	}
	copy_path = _strdup(real_path);
	path = copy_path;
	path = strtok(path, ":");
	while (path)
	{
		vector = concatenate(args, path);
		rreturn_stat = stat_func(vector);
		if (rreturn_stat == 0)
		{
			arr = add_arr(args, vector);
			while (arr[count])
				count++;
			arr[count + 1] = copy_path;
			return (free(args), arr);
		}
		path = strtok(NULL, ":");
		free(vector);
	}
	print_error(av, counter, arguments);
	return (free(args), free(copy_path), NULL);
}
