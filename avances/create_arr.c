#include "shell.h"

char **create_arr(char *str_g)
{
	char *real_path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	char *vector = NULL;
	char *copy_path = NULL;
	char *path = NULL;
	char **arr = NULL;
	int rtrn_stat, count = 0;

	copy_path = strdup(real_path);
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
			{
				count++;
			}
			arr[count + 1] = copy_path;
			return (arr);
		}
		free(vector);
		path = strtok(NULL, ":");
	}
	printf("No found: %s\n", str_g);
	free(copy_path);
	return NULL;
}
