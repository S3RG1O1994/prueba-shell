#include "shell.h"

/**
 * main - stat example
 *
 * Return: Always 0.
 */
int stat_func(char *command)
{
	struct stat st;

        if (stat(command, &st) == 0)
        {
		printf("%s:", command);
		printf(" FOUND\n");
		return (0);
        }
	return (1);
}
