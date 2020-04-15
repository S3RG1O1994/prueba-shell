#include "shell.h"

/**
 * _merge - Unifies the functions: env and exit.
 * @args: Contains the arguments.
 * @env: Contains the enviroment.
 *
 * Return: Returns 0 if the command entered is "env",
 * the command "exit" ends the program and returns 1 if nothing matches.
 */
int _merge(char *args, char **env)
{
	int func_return = 0;

	func_return = print_env(args, env);
	if (func_return == 0)
		return (0);
	check_exit(args);

	return (1);
}
