#include "shell.h"

int main() {
	char *str_g = "ls -la /usr/";
	char *real_path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	char *vector;
	char *copy_path;
	char *path;
	int rtrn_stat;

	copy_path = strdup(real_path);
	path = copy_path;
	path = strtok(path, ":");
	while (path)
	{
		vector = concatenate(str_g, path);
		rtrn_stat = stat_func(vector);
		if (rtrn_stat == 0)
		{
			free(vector);
			free(copy_path);
			return (0);
		}
		free(vector);
		path = strtok(NULL, ":");
	}

	printf("No se encontro el comando: %s\n", str_g);

	free(copy_path);
	return 0;
}
