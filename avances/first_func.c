#include "shell.h"

void first_func(void)
{
	int bytes_read;
	size_t size = 0;
	char *string = NULL, **arr = NULL;
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
		free(string);
		return;
	}
	if (string[0] == '\n')
	{
		free(string);
		return;
	}
	arr = create_arr(string);
	pid = fork();
	if (pid > 0)
		wait(&pid);
	else if (pid == 0)
	{
		if (execve(arr[0], arr, NULL) == -1)
			perror("Error en execve");
	}
	else
		perror("Error else");

	free(string);
	free_all(arr);
}
