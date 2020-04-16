#include "shell.h"

/**
 * main - Boot the shell with an infinite loop so that it is always active.
 * @ac: Cointains the numbers of vectors.
 * @av: Cointains the arguments.
 * @env: Contains de enviroment.
 *
 * Return: Allways is 0.
 */
int main(__attribute__((unused)) int ac, char **av, char **env)
{
	ssize_t bytes_read;
	size_t size = 0;
	char *args = NULL, **arr = NULL;
	pid_t pid;
	int counter = 0, val;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		short_func(&counter);
		bytes_read = getline(&args, &size, stdin);
		if (bytes_read == -1)
			return (free(args), _putchar('\n'), 0);
		if (*args == '\n')
			continue;
		else
		{
			val = validator(args);
			if (val != 0)
				continue;
			arr = create_arr(args, env, av[0], counter);
			pid = fork();
			if (pid > 0)
				wait(&pid);
			else if (pid == 0)
			{
				if (arr)
				{
					if (execve(arr[0], arr, NULL) == -1)
						perror("Error execve:");
				}
				return (free(args), free(arr), 0);
			}
			else
				perror("Error");
		}
		if (arr)
			free_all(arr);
	}
	return (free(args), 0);
}
