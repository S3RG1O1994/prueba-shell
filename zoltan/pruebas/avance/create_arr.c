#include "shell.h"

char **create_arr(char *args, char **env)
{
	char *real_path = _getenv("PATH", env);
	char *copy_path = NULL;
	char *path = NULL;
	char *vector = NULL;
	char **arr = NULL;
	int return_stat;
	int count = 0;

	copy_path = _strdup(real_path);
	path = copy_path;
	path = strtok(path, ":");
	while (path)
	{
		vector = concatenate(args, path);
		return_stat = stat_func(vector);
		if (return_stat == 0)
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
