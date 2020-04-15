#include "shell.h"

char **create_arr(char *args, char **env)
{
	char **arr_ejemplo = NULL, *real_path = _getenv("PATH", env);

	arr_ejemplo = malloc(sizeof(char *) * 3);
	if (!arr_ejemplo)
		return (NULL);
	arr_ejemplo[0] = "/bin/ls";
	arr_ejemplo[1] = "-l";
	arr_ejemplo[2] = NULL;
	return (arr_ejemplo);
}
