#include "shell.h"

/**
 * signalhandler - function
 * @n: numbers of signal
 */
void signalhandler(__attribute__((unused)) int n)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - function
 * @ac: numbers of arguments
 * @av: arguments
 *
 * Return: Allways 0.
 */
int main(__attribute__((unused)) int ac, char **av)
{
	ssize_t bytes_read = 0;
	size_t size = 0;
	char *args = NULL, **arr = NULL;
	pid_t pid;
	int r_isatty = 0;

	if (!(isatty(STDIN_FILENO)))
		r_isatty = 1;
	signal(SIGINT, signalhandler);
	while (1)
	{
		if (r_isatty == 0)
			write(STDOUT_FILENO, "$ ", 2);
		bytes_read = getline(&args, &size, stdin);
		if (bytes_read == -1)
		{
			if (r_isatty == 0)
				_putchar('\n');
			return (free(args), 0);
		}
		arr = create_arr(args);
		pid = fork();
		if (pid > 0)
			wait(&pid);
		else if (pid == 0)
		{
			if (execve(arr[0], arr, NULL) == -1)
				perror(av[0]);
			free(args);
			free(arr[0]);
			free(arr);
			return (0);
		}
		else
			perror("Error");
		free(arr[0]);
		free(arr);
	}
	return (0);
}
