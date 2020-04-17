#include "shell.h"
/**
 * process - Function administrator of process father and daugther.
 * @arr: matrix of direction plus command for function exceve.
 * @av: Name of program.
 * @args: command insert by getline..
 * Return: integrer Zero..
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
