#include "shell.h"

/**
 * main - Main function
 *
 * Return: always 0 or 1.
 */
int main(void)
{
	pid_t pid;

	while (1)
	{
		pid = fork();
		if (pid > 0)
			wait(&pid);
		else if (pid == 0)
			first_func();
		else
		{
			perror("Error:");
			return (1);
		}
	}
	return (0);
}
