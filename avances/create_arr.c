#include "shell.h"

/**
 * create_arr - Assign the command path to the array.
 * @str_g: - String obtained from the getline function.
 *
 * Return: Returns an array to run.
 */
char **create_arr(char *str_g)
{
	int rtrn_stat, count = 0;
	char *real_path = _getenv("PATH"), *vector = NULL;
	char *path = NULL, **arr = NULL, *copy_path = NULL;

	copy_path = _strdup(real_path);
	path = copy_path;
	path = strtok(path, ":");
	while (path)
	{
		vector = concatenate(str_g, path);
		rtrn_stat = stat_func(vector);
		if (rtrn_stat == 0)
		{
			arr = add_arr(str_g, vector);
			while (arr[count])
				count++;
			arr[count + 1] = copy_path;
			return (arr);
		}
		free(vector);
		path = strtok(NULL, ":");
	}
	printf("No found: %s", str_g);
	free(copy_path);
	return (NULL);
}
