#include "shell.h"

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
	//free(args);
	return (0);
}
