#include "shell.h"

/**
 * short_func - funcion
 * @counter: a
 */
void short_func(int *counter)
{
	counter += 1;
	write(STDOUT_FILENO, "$ ", 2);
}
