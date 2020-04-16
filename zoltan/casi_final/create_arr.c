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
<<<<<<< HEAD
	char *real_path = _getenv("PATH", env);
	char *copy_path = NULL;
	char *path = NULL;
	char *vector = NULL;
	char **arr = NULL;
	int rreturn_stat;
	int count = 0;

	count = _merge(args, env);
	if (count == 0)
		return (NULL);

	count = 0;
=======
	char *real_path = _getenv("PATH", env), *copy_path = NULL;
	char *path = NULL, *vector = NULL, **arr = NULL;
	int rreturn_stat, count = 0, count_2 = 0, validator;

	validator = _merge(args, env);
	if (validator == 0)
		return (NULL);
	if (args[0] == '/')
	{
		arr = absolute_path(args, av, counter);
		if (!arr)
			return (free(copy_path), NULL);
		while (arr[count_2])
				count_2++;
		arr[count_2 + 1] = copy_path;
		return (arr);
	}
>>>>>>> 9e43e8cac13aff0c4cefb30972cc0593de6bb05b
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
<<<<<<< HEAD
	print_error(av, counter, args);
	free(copy_path);
	return (NULL);
=======
	return (print_error(av, counter, args), free(copy_path), NULL);
>>>>>>> 9e43e8cac13aff0c4cefb30972cc0593de6bb05b
}
