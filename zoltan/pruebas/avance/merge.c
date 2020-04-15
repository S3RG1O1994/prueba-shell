#include "shell.h"

int _merge(char *args, char **env)
{
	int return_func = 0;

	return_func = print_env(args, env);
        if (return_func == 0)
		return (0);
	check_exit(args);

	return (1);
}
