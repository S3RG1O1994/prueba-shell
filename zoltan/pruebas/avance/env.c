#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int print_env(char *string, char **environ)
{
	unsigned int j = 0, h = 0;
	char *env = "env";

	while (string[j] != '\n')
	{
		if(string[j] == env[h])
			h++;
		j++;
	}

	if (j == h)
	{
		for (unsigned int i = 0 ;environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
		return (0);
	}
	return (1);
}
