#include "shell.h"

void first_func(void)
{
	int bytes_read;
	size_t size = 0;
	char *string = NULL, **argv = NULL;
	pid_t pid;

	_putchar('$');
	_putchar(' ');

	string = malloc(sizeof(char) * size);
	if (string == NULL)
		return;
	bytes_read = getline(&string, &size, stdin);

	if(bytes_read == -1)
	{
		printf("error bytes_read == -1\n");
		return;
	}
	if (string[0] == '\n')
		return;
	else
	{
		argv = add_arr(string);
		pid = fork();
		if (pid > 0)
		{
			wait(&pid);
			free(string);
			free(argv[0]);
			free(argv);
		}
		else if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error en execve:");
		}
		else
			perror("Error else:");
	}
}
