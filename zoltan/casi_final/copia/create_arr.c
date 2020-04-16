#include "shell.h"

/**
 * create_arr - Create an array with executable path and possible arguments.
 * @args: Contains the commands.
 * @env: Contains the environment.
 * @av: contains the first argument.
 * @counter: General counter.
 *
 * Return: Allways matrix or NULL.
 */
char **create_arr(char *args, char **env, char *av, int counter)
{
	char *real_path = _getenv("PATH", env), *copy_path = NULL;
	char *path = NULL, *vector = NULL, **arr = NULL;
	int rreturn_stat, count = 0, count_2 = 0, validator;

	validator = _merge(args, env);
	if (validator == 0)
		return (NULL);
	if (args[0] == '/')
	{
		arr = absolute_path(args);
		if (!arr)
			return (free(copy_path), NULL);
		while (arr[count_2])
				count_2++;
		arr[count_2 + 1] = copy_path;
		count = 0;
		while (arr[count])
		{
			printf("%s\n", arr[count]);
			count++;
		}

		return (arr);
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
			return (arr);
		}
		path = strtok(NULL, ":");
		free(vector);
	}
	return (print_error(av, counter, args), free(copy_path), NULL);
}
