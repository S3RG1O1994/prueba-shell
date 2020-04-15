#include "shell.h"

/**
 * stat_func - Check if there is an executable in the assigned path.
 * @command: Path whit commands.
 *
 * Return: Always 0 or 1.
 */
int stat_func(char *command)
{
	struct stat st;

	if (stat(command, &st) == 0)
		return (0);

	return (1);
}
