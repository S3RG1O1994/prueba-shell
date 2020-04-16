#include "shell.h"

void signalhandler(__attribute__((unused)) int n)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}

int main(__attribute__((unused)) int ac, char **av)
{
	ssize_t bytes_read = 0;
	size_t size = 0;
	char *args = NULL, **arr = NULL, *tmp = NULL;
	pid_t pid;
	int count, r_isatty = 0;

	if (!(isatty(STDIN_FILENO)))
		r_isatty = 1;
	signal(SIGINT, signalhandler);
	while (1)
	{
		count = 0;
		if (r_isatty == 0)
			write(STDOUT_FILENO, "$ ", 2);
		bytes_read = getline(&args, &size, stdin);
		if (bytes_read == -1)
		{
			if(r_isatty == 0)
				_putchar('\n');
			return (free(args), 0);
		}
		while (args[count] != '\n')
			count++;
		args[count] = '\0';
		arr = malloc(sizeof(char *) * 2);
		if (!arr)
		{
			free(args);
			return(0);
		}
		tmp = shortener(args);
		arr[0] = space_eliminator(tmp);
		arr[1] = NULL;
		free(tmp);
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
