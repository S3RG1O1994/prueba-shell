#include "shell.h"

void short_func(int *counter)
{
	counter += 1;
	write(STDOUT_FILENO, "$ ", 2);
}
