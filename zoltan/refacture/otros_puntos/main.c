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
	char *args = NULL, **arr = NULL, *arguments = NULL;
	int r_isatty = 0, val = 0, counter = 0;

	if (!(isatty(STDIN_FILENO)))
		r_isatty = 1;
	signal(SIGINT, signalhandler);
	while (1)
	{
		counter++;
		if (r_isatty == 0)
			write(STDOUT_FILENO, "$ ", 2);
		bytes_read = getline(&args, &size, stdin);
		if (bytes_read == -1)
		{
			if (r_isatty == 0)
				_putchar('\n');
			return (free(args), 0);
		}
		val = validator(args);
		if (val != 0)
			continue;
	        arguments = preparer(args);
		arr = create_arr(arguments, av[0], counter);
		if (arr)
		{
			process(arr, av[0], args);
			free_all(arr);
			free(arguments);
		}
		else
			free(arguments);
	}
	return (0);
}
