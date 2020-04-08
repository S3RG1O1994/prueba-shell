#include "shell.h"

int main(void)
{
	pid_t pid;

	while (1)
	{

		pid = fork();
		if ( pid > 0)
		{
			wait(&pid);
		}
		else if (pid == 0)
		{
			first_func();
		}
		else
		{
			perror("Error:");
			return (1);
		}
	}
	return (0);
}
