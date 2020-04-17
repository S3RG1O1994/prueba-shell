#include "shell.h"

/**
 * process - create process father and son
 * @arr: array with arguments.
 * @av: name of program.
 * @args: original arguments
 *
 * Return: Allways 0
 */
int process(char **arr, char *av, char *args)
{
	pid_t pid;
	(void) args;

	pid = fork();
	if (pid > 0)
		wait(&pid);
	else if (pid == 0)
	{
		if (arr)
		{
			if (execve(arr[0], arr, NULL) == -1)
				perror(av);
		}
		exit(0);
	}
	else
		perror(av);
	return (0);
}
