#include "shell.h"

/**
 * create_arr - Create an array with executable path and possible arguments.
 * @args: Contains the commands.
 * @env: Contains the environment.
 *
 * Return: Allways matrix or NULL.
 */
char **create_arr(char *args, char **env)
{
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
	printf("no se encontro comando\n");
	free(copy_path);
	return (NULL);
}
